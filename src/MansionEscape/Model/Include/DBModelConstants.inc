std::string const DBModel::DBDir("~/.mansionescape/db");
std::string const DBModel::DBFile("~/.mansionescape/db/savedata.sqlite");

std::string const DBModel::InventoryTable("Inventory");
std::string const DBModel::ProgressTable("Progress");
std::string const DBModel::PlayerDataTable("PlayerData");


std::string const DBModel::InventoryCreateQuery(
R"(
CREATE TABLE IF NOT EXISTS
  Inventory
  (
    id  UNSIGNED INTEGER PRIMARY KEY ASC,
    label VARCHAR
  );
)");


std::string const DBModel::ProgressCreateQuery(
R"(
CREATE TABLE IF NOT EXISTS
  Progress
  (
      id UNSIGNED INTEGER PRIMARY KEY ASC,
      flagname VARCHAR,
      isset BOOLEAN
  );
)");

std::string const DBModel::PlayerDataCreateQuery(
R"(
CREATE TABLE IF NOT EXISTS
  Playerdata
  (
    id UNSIGNED INTEGER PRIMARY KEY ASC,
    currentroom VARCHAR
  );
)");
