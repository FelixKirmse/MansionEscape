#pragma once
#include <string>
#include <map>
#include "Model/Item.h"
#include "Controller/RoomPerspective.h"

namespace MansionEscape
{
class AssetHolder
{
public:
  typedef std::map<std::string, Item> ItemMap;
  typedef std::map<std::string, RoomPerspective> RoomMap;

  AssetHolder();

  void LoadAssets();

  Item const& GetItem(std::string const& name);
  RoomPerspective const& GetRoom(std::string const& label);

private:
  void LoadRooms();
  void LoadItems();

  ItemMap _items;
  RoomMap _rooms;

  static std::string const ItemsPath;
  static std::string const RoomsPath;
};
}
