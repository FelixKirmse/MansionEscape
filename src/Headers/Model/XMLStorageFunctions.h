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
void save(Archive& ar, MansionEscape::Progress const& progress, unsigned int const version)
{
  ar & BOOST_SERIALIZATION_NVP(progress.GetFlags());
}

template<class Archive>
void load(Archive& ar, MansionEscape::Progress& progress, unsigned int const version)
{
  MansionEscape::Progress::FlagMap flagMap;
  ar & BOOST_SERIALIZATION_NVP(flagMap);
  progress.SetFlags(flagMap);
}

template<class Archive>
void serialize(Archive& ar, MansionEscape::Progress& progress, unsigned int const version)
{
  boost::serialization::split_free(ar, progress, version);
}

template<class Archive>
void save(Archive& ar, MansionEscape::Item const& item, unsigned int const version)
{
  ar & BOOST_SERIALIZATION_NVP(item.GetLabel());
}

template<class Archive>
void load(Archive& ar, MansionEscape::Item& item, unsigned int const version)
{
  std::string label;
  ar & BOOST_SERIALIZATION_NVP(label);
  item.LoadItemFromLabel(label);
}

template<class Archive>
void serialize(Archive& ar, MansionEscape::Item& item, unsigned int const version)
{
  boost::serialization::split_free(ar, item, version);
}

template<class Archive>
void save(Archive& ar, MansionEscape::Inventory const& inventory, const unsigned int version)
{
  MansionEscape::Inventory::ItemVec& items(inventory.GetItems());
  size_t size = items.size();
  ar & BOOST_SERIALIZATION_NVP(size);

  for(auto* item : inventory.GetItems())
  {
    ar & BOOST_SERIALIZATION_NVP(item->GetLabel());
  }
}

template<class Archive>
void load(Archive& ar, MansionEscape::Inventory& inventory, const unsigned int version)
{
  size_t size;
  ar & BOOST_SERIALIZATION_NVP(size);
  for(size_t i = 0; i < size; ++i)
  {
    std::string label;
    ar & BOOST_SERIALIZATION_NVP(label);
    inventory.AddItemFromLabel(label);
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
  ar & BOOST_SERIALIZATION_NVP(playerData.GetProgress());
  ar & BOOST_SERIALIZATION_NVP(playerData.GetInventory());
  ar & BOOST_SERIALIZATION_NVP(playerData.GetRoomLabel());
}

template<class Archive>
void load(Archive& ar, MansionEscape::PlayerData& playerData, unsigned int const version)
{
  using namespace MansionEscape;
  Progress progress;
  ar & BOOST_SERIALIZATION_NVP(progress);
  playerData.SetProgress(progress);

  Inventory inventory;
  ar & BOOST_SERIALIZATION_NVP(inventory);
  playerData.SetInventory(inventory);

  std::string roomLabel;
  ar & BOOST_SERIALIZATION_NVP(roomLabel);
  playerData.SetRoomLabel(roomLabel);
}

template<class Archive>
void serialize(Archive& ar, MansionEscape::PlayerData& playerData, unsigned int const version)
{
  boost::serialization::split_free(ar, playerData, version);
}

}
}
