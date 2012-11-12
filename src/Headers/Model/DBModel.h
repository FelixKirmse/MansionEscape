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

  sqlite3* _database;

  static std::string const DBDir;
  static std::string const DBFile;
  static std::string const InventoryTable;
  static std::string const ProgressTable;
  static std::string const PlayerDataTable;

  static std::string const InventoryCreateQuery;
  static std::string const ProgressCreateQuery;
  static std::string const PlayerDataCreateQuery;
};
/*!\}*/
}
