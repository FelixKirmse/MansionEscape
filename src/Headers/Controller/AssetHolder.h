#pragma once
#include <string>
#include <map>
#include "Model/Item.h"
#include "Controller/RoomView.h"

namespace MansionEscape
{
class AssetHolder
{
public:
  typedef std::map<std::string, Item> ItemMap;
  typedef std::map<std::string, RoomView> RoomMap;

  AssetHolder();

  void LoadAssets();

  Item const& GetItem(std::string const& name) const;
  RoomView const& GetRoom(std::string const& label) const;

private:
  void LoadRooms();
  void LoadItems();

  ItemMap _items;
  RoomMap _rooms;

  static std::string const ItemsPath;
  static std::string const RoomsPath;
};
}
