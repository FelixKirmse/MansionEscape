#include "Model/AssetHolder.h"
#include "boost/filesystem.hpp"
#include "boost/archive/xml_iarchive.hpp"
#include <fstream>

namespace MansionEscape
{
std::string const AssetHolder::ItemsPath("content/items");
std::string const AssetHolder::RoomsPath("content/rooms");


AssetHolder::AssetHolder()
  : _items(), _rooms()
{
}

Item const& AssetHolder::GetItem(std::string const& name) const
{
  return _items.find(name)->second;
}

RoomView const& AssetHolder::GetRoom(std::string const& label) const
{
  RoomMap::const_iterator iterator = _rooms.find(label);
  if(iterator == _rooms.end())
    throw "FUCK";
  return _rooms.find(label)->second;
}

void AssetHolder::LoadAssets()
{
  LoadRooms();
  LoadItems();
}

void AssetHolder::LoadItems()
{
  using namespace boost::filesystem;
  using namespace std;
  using namespace boost::archive;

  path itemsPath(ItemsPath);
  directory_iterator end;
  for(directory_iterator i(itemsPath); i != end; ++i)
  {
    if(!is_directory(i->status()))
      continue;

    path xmlFilePath(i->path().string() + "/config.xml");
    ifstream xmlFile(xmlFilePath.string());
    xml_iarchive ia(xmlFile);

    Item newItem;
    ia >> BOOST_SERIALIZATION_NVP(newItem);
    _items[newItem.GetName()] = newItem;
  }
}

void AssetHolder::LoadRooms()
{
  using namespace boost::filesystem;
  using namespace std;
  using namespace boost::archive;

  path roomsPath(RoomsPath);
  directory_iterator end;
  for(directory_iterator i(roomsPath); i != end; ++i)
  {
    if(!is_directory(i->status()))
      continue;
    for(directory_iterator roomDir(i->path()); roomDir != end; ++roomDir)
    {
      path roomPath(roomDir->path().string() + "/config.xml");
      ifstream roomConfig(roomPath.string());
      xml_iarchive ia(roomConfig);

      RoomView newRoom;
      ia >> BOOST_SERIALIZATION_NVP(newRoom);
      _rooms[newRoom.GetViewLabel()] = newRoom;
    }
  }
}
}
