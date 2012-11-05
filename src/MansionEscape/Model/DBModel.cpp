#include "Model/DBModel.h"
#include <iostream>
#include <boost/filesystem.hpp>
#include "Model/Item.h"
#include "Model/Progress.h"


namespace MansionEscape
{
#include "Include/DBModelConstants.inc"

DBModel::DBModel()
  : BaseModel(), _database(0)
{
  sqlite3_open(DBFile.c_str(), &_database);

  Query(InventoryCreateQuery);
  Query(ProgressCreateQuery);
  Query(PlayerDataCreateQuery);
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

  stringstream query;
  query << "INSERT INTO " << PlayerDataTable << " (currentroom) VALUES (";
  query << "'" << playerData.GetRoomLabel() << "');";
  Query(query.str());
  ResetStream(query);

  query << "INSERT INTO " << InventoryTable << endl;
  query << "SELECT 'DUMMYITEM' AS label" << endl;
  for(auto const& item : playerData.GetInventory().GetItems())
    query << "UNION SELECT '" << item << "'" << endl;

  query << ";";
  Query(query.str());
  ResetStream(query);

  query << "INSERT INTO " << ProgressTable << endl;
  query << "SELECT 'DUMMYFLAG' AS flagname, 1 AS isset)" << endl;
  for(auto& flag : playerData.GetProgress().GetFlags())
    query << "UNION SELECT '" << flag.first << "', " << (flag.second ? 1 : 0) << endl;

  query << ";";
  Query(query.str());
}

void DBModel::Load()
{
  using namespace std;  
  PlayerData& playerData = GetPlayerData();
  stringstream query;
  query << "SELECT currentroom FROM " << PlayerDataTable << ";";
  QueryResult result = Query(query.str());
  ResetStream(query);

  playerData.SetRoomLabel(result[0][0]);

  query << "SELECT label FROM " << InventoryTable << ";";
  result = Query(query.str());
  ResetStream(query);
  Inventory& inventory = playerData.GetInventory();

  for(auto& row : result)
  {
    inventory.AddItem(row[0]);
  }

  query << "SELECT flagname, isset FROM " << ProgressTable << ";";
  result = Query(query.str());
  Progress& progress = playerData.GetProgress();

  for(auto& row : result)
  {
    progress.SetFlag(row[0], row[1] == "1");
  }
}

void DBModel::Delete()
{
  Query("DELETE FROM Inventory;");
  Query("DELETE FROM Progress;");
  Query("DELETE FROM PlayerData;");
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
}
