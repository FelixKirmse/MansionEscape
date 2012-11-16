#include "Model/DBModel.h"
#include <iostream>
#include <boost/filesystem.hpp>
#include "Model/Item.h"
#include "Model/Progress.h"
#include <boost/format.hpp>


namespace MansionEscape
{
#include "Include/DBModelConstants.inc"

DBModel::DBModel()
  : BaseModel(), _database(0)
{
  using namespace boost::filesystem;
  path dbDir(DBDir);
  if(!exists(dbDir))
    create_directory(dbDir);

  sqlite3_open(DBFile.c_str(), &_database);

  Query(ItemCreateQuery);
  Query(FlagCreateQuery);
  Query(saveSlotCreateQuery);
  Query(InventoryCreateQuery);
  Query(ProgressCreateQuery);
}

DBModel::~DBModel()
{
  sqlite3_close(_database);
}

void DBModel::Save()
{
  using namespace std;
  Delete();

  PlayerData& playerData = GetPlayerData();
  int saveSlot = GetSaveSlot();

  boost::format saveSlotQuery("INSERT INTO Saveslot (slot, currentroom) VALUES (%d, '%s');");
  saveSlotQuery
      % saveSlot
      % playerData.GetRoomLabel();
  Query(saveSlotQuery.str());

  for(Item const* item : playerData.GetInventory())
  {
    boost::format inventoryQuery("INSERT INTO Inventory (saveslot, item_id) VALUES (%d, %d);");
    inventoryQuery
        % saveSlot
        % InsertItem(item);
    Query(inventoryQuery.str());
  }

  for(auto const& flag : playerData.GetProgress().GetFlags())
  {
    boost::format progressQuery("INSERT INTO Progress (saveslot, flag_id, isset) VALUES (%d, %d, %d);");
    progressQuery
        % saveSlot
        % InsertFlag(flag.first)
        % (playerData.GetProgress().GetFlag(flag.first) ? 1 : 0);
    Query(progressQuery.str());
  }
}

void DBModel::Load()
{
  using namespace std;
  if(!SaveSlotExists())
  {
    StartNewGame();
    return;
  }

  PlayerData& playerData = GetPlayerData();
  Inventory& inventory = playerData.GetInventory();
  Progress& progress = playerData.GetProgress();
  int saveSlot = GetSaveSlot();

  boost::format loadQuery(LoadFormatQuery);
  loadQuery
      % saveSlot;
  QueryResult result = Query(loadQuery.str());

  /******************************
   * Result-Row-Struktur:       *
   ******************************
   * [0] = Saveslot.currentRoom *
   * [1] = Flag.name            *
   * [2] = Progress.isset       *
   * [3] = Item.name            *
   *****************************/
  // Wir müssen den Raum nur einmal setzen
  playerData.SetRoomLabel(result[0][0]);
  for(auto const& row : result)
  {
    progress.SetFlag(row[1], row[2] == "1");
    inventory.AddItem(row[3]);
  }
}

void DBModel::Delete()
{
  boost::format query(DeleteRelationsFormatQuery);
  query
      % GetSaveSlot();
  if(sqlite3_exec(_database, query.str().c_str(), 0, 0, 0) != SQLITE_OK)
    PrintError(query.str());
}


DBModel::QueryResult DBModel::Query(std::string const& query)
{
  sqlite3_stmt* statement;
  QueryResult results;

  if(sqlite3_prepare_v2(_database, query.c_str(), -1, &statement, 0) != SQLITE_OK)
  {
    PrintError(query);
    return results;
  }

  for(int result = sqlite3_step(statement); result == SQLITE_ROW; result = sqlite3_step(statement))
  {
    std::vector<std::string> values;
    int cols = sqlite3_column_count(statement);
    for(int col = 0; col < cols; ++col)
    {
      values.push_back((char*)sqlite3_column_text(statement, col));
    }
    results.push_back(values);
  }
  sqlite3_finalize(statement);

  PrintError(query);
  return results;
}

void DBModel::PrintError(std::string const& query)
{
  std::string error(sqlite3_errmsg(_database));
  if(error != "not an error")
    std::cout << query << " " << error << std::endl;
}

void DBModel::ResetStream(std::stringstream& stream)
{
  stream.str("");
  stream.clear();
}


int DBModel::GetID(std::string const& table, std::string const& value)
{
  boost::format query(GetIDFormatQuery);
  query
      % table
      % value;

  sqlite3_stmt* statement;
  if(sqlite3_prepare_v2(_database, query.str().c_str(), -1, &statement, 0) != SQLITE_OK)
  {
    PrintError(query.str());
    return -2; // Interner Fehler
  }

  if(sqlite3_step(statement) == SQLITE_OK) // value nicht gefunden
  {
    sqlite3_finalize(statement);
    return -1; // ID nicht gefunden
  }
  int id = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  return id;
}

int DBModel::GetFlagID(std::string const& flagName)
{
  return GetID("Flag", flagName);
}

int DBModel::GetItemID(Item const* item)
{
  return GetID("Item", item->GetName());
}

int DBModel::Insert(std::string const& table, std::string const& value)
{
  boost::format query(InsertIntoFormatQuery);
  query
      % table
      % value;
  Query(query.str());
  return GetID(table, value);
}

bool DBModel::SaveSlotExists()
{
  boost::format query("SELECT COUNT(slot) FROM Saveslot WHERE slot = %d");
  query
      % GetSaveSlot();
  QueryResult result = Query(query.str());
  return result[0][0] == "1";
}

int DBModel::InsertFlag(std::string const& flagName)
{
  return Insert("Flag", flagName);
}

int DBModel::InsertItem(Item const* item)
{
  return Insert("Item", item->GetName());
}
}
