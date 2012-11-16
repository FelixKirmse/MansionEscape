#pragma once
#include "Model/PlayerData.h"
#include "Model/Progress.h"
#include "Model/Inventory.h"
#include "Model/Item.h"
#include <boost/serialization/serialization.hpp>
#include <boost/serialization/map.hpp>

namespace boost
{
namespace serialization
{
template<class Archive>
void save(Archive& ar, MansionEscape::Inventory const& inventory, const unsigned int version)
{
  MansionEscape::Inventory::ItemVec const& items(inventory.GetItems());
  size_t size = items.size();
  ar & make_nvp("size", size);

  for(MansionEscape::Item const* item : inventory)
  {
    ar & make_nvp("item", item->GetName());
  }
}

template<class Archive>
void load(Archive& ar, MansionEscape::Inventory& inventory, const unsigned int version)
{
  size_t size;
  ar & make_nvp("size", size);
  for(size_t i = 0; i < size; ++i)
  {
    std::string itemLabel;
    ar & make_nvp("item", itemLabel);
    inventory.AddItem(itemLabel);
  }
}

template<class Archive>
void serialize(Archive& ar, MansionEscape::Inventory& inventory, unsigned const int version)
{
  boost::serialization::split_free(ar, inventory, version);
}

template<class Archive>
void save(Archive& ar, MansionEscape::PlayerData const& playerData, unsigned int const version)
{
  MansionEscape::Progress::FlagMap flags = playerData.GetProgress().GetFlags();
  ar & make_nvp("flags", flags);
  ar & make_nvp("inventory", playerData.GetInventory());
  ar & make_nvp("roomlabel", playerData.GetRoomLabel());
}

template<class Archive>
void load(Archive& ar, MansionEscape::PlayerData& playerData, unsigned int const version)
{
  using namespace MansionEscape;
  Progress::FlagMap flagMap;
  ar & make_nvp("flags", flagMap);
  Progress progress;
  progress.SetFlags(flagMap);
  playerData.SetProgress(progress);

  IModel* model = playerData.GetInventory().GetModel();
  Inventory inventory;
  inventory.SetModel(model);
  ar & make_nvp("inventory", inventory);
  inventory.SetProgress(&playerData.GetProgress());
  playerData.SetInventory(inventory);

  std::string roomLabel;
  ar & make_nvp("roomlabel", roomLabel);
  playerData.SetRoomLabel(roomLabel);
}

template<class Archive>
void serialize(Archive& ar, MansionEscape::PlayerData& playerData, unsigned int const version)
{
  boost::serialization::split_free(ar, playerData, version);
}

}
}
