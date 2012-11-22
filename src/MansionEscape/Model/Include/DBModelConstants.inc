std::string const DBModel::DBDir(std::string(getenv("HOME")) + "/.mansionescape/db");
std::string const DBModel::DBFile(std::string(getenv("HOME")) + "/.mansionescape/db/savedata.sqlite");

std::string const DBModel::InventoryTable("Inventory");
std::string const DBModel::ProgressTable("Progress");
std::string const DBModel::PlayerDataTable("PlayerData");


std::string const DBModel::ActivateForeignKeys(
R"(
PRAGMA foreign_keys = ON;
)");

std::string const DBModel::ItemCreateQuery(
R"(
CREATE TABLE IF NOT EXISTS
  Item
  (
    id  INTEGER PRIMARY KEY AUTOINCREMENT,
    name VARCHAR NOT NULL
  );
)");


std::string const DBModel::FlagCreateQuery(
R"(
CREATE TABLE IF NOT EXISTS
  Flag
  (
      id INTEGER PRIMARY KEY AUTOINCREMENT,
      name VARCHAR NOT NULL
  );
)");

std::string const DBModel::saveSlotCreateQuery(
R"(
CREATE TABLE IF NOT EXISTS
  saveslot
  (
    slot INTEGER PRIMARY KEY AUTOINCREMENT,
    currentroom VARCHAR NOT NULL
  );
)");

std::string const DBModel::InventoryCreateQuery(
R"(
CREATE TABLE IF NOT EXISTS
  Inventory
  (
    saveslot INTEGER NOT NULL,
    item_id  INTEGER NOT NULL,
    FOREIGN KEY(saveSlot) REFERENCES saveSlot(slot),
    FOREIGN KEY(item_id) REFERENCES Item(id)
  );
)");

std::string const DBModel::ProgressCreateQuery(
R"(
CREATE TABLE IF NOT EXISTS
  Progress
  (
    saveslot INTEGER NOT NULL,
    flag_id INTEGER NOT NULL,
    isset BOOLEAN NOT NULL,
    FOREIGN KEY(saveSlot) REFERENCES saveSlot(slot),
    FOREIGN KEY(flag_id) REFERENCES Flag(id)
  );
)");

std::string const DBModel::GetIDFormatQuery(
R"(
SELECT
  id
FROM
  %s
WHERE
  name = '%s';
)");


// Source für diese Art Query: http://stackoverflow.com/a/531147/1027937
std::string const DBModel::InsertIntoFormatQuery(
R"(
INSERT INTO
  %1%
  (
    name
  )
SELECT
  '%2%'
WHERE NOT EXISTS
  (
    SELECT
      1
    FROM
      %1%
    WHERE
      name = '%2%'
  );
)");


std::string const DBModel::DeleteRelationsFormatQuery(
R"(
DELETE FROM
  Inventory
WHERE
  saveslot = %1%;
DELETE FROM
  Progress
WHERE
  saveSlot = %1%;
DELETE FROM
  saveSlot
WHERE
  slot = %1%;
)");

std::string const DBModel::LoadFormatQuery(
R"(
SELECT
  Saveslot.currentroom,
  Flag.name,
  Progress.isset,
  Item.name
FROM
  Saveslot
LEFT OUTER JOIN
  Progress
ON
  Saveslot.slot = Progress.saveslot
LEFT OUTER JOIN
  Flag
ON
  Progress.flag_id = Flag.id
LEFT OUTER JOIN
  Inventory
ON
  Saveslot.slot = Inventory.saveslot
LEFT OUTER JOIN
  Item
ON
  Inventory.item_id = Item.id
WHERE
  Saveslot.slot = %d;
)");
