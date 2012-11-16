#pragma once
#include "Model/BaseModel.h"
#include <sqlite3.h>
#include <vector>
#include <sstream>

namespace MansionEscape
{
/*!
  \addtogroup Model
  \{
*/
/*!
  \brief IModel that uses SQLite to save data
  \class DBModel Model/DBModel.h
*/
class DBModel : public BaseModel
{
public:
  DBModel();
  ~DBModel();

  void Save();
  void Load();
  void Delete();

private:
  typedef std::vector<std::vector<std::string> > QueryResult;

  QueryResult Query(std::string const& query);
  void PrintError(std::string const& query);
  void RecreateTables();
  void ResetStream(std::stringstream& stream);

  int GetFlagID(std::string const& flagName);
  int GetItemID(Item const* item);

  int GetID(std::string const& table, std::string const& value);

  int InsertItem(Item const* item);
  int InsertFlag(std::string const& flagName);
  int Insert(std::string const& table, std::string const& value);

  bool SaveSlotExists();

  sqlite3* _database;

  static std::string const DBDir;
  static std::string const DBFile;
  static std::string const InventoryTable;
  static std::string const ProgressTable;
  static std::string const PlayerDataTable;

  static std::string const ActivateForeignKeys;
  static std::string const GetIDFormatQuery;
  static std::string const InsertIntoFormatQuery;
  static std::string const DeleteRelationsFormatQuery;

  static std::string const InventoryCreateQuery;
  static std::string const ProgressCreateQuery;
  static std::string const saveSlotCreateQuery;
  static std::string const ItemCreateQuery;
  static std::string const FlagCreateQuery;

  static std::string const LoadFormatQuery;
};
/*!\}*/
}
