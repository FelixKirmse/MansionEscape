#include "Model/PlayerData.h"

namespace MansionEscape
{

Progress const& PlayerData::GetProgress() const
{
  return _progress;
}

Progress& PlayerData::GetProgress()
{
  return _progress;
}

Inventory& PlayerData::GetInventory()
{
  return _inventory;
}

Inventory const& PlayerData::GetInventory() const
{
  return _inventory;
}

std::string const& PlayerData::GetRoomLabel() const
{
  return _roomLabel;
}

void PlayerData::SetRoomLabel(std::string const& roomLabel)
{
  _roomLabel = roomLabel;
}

void PlayerData::SetProgress(Progress progress)
{
  _progress = progress;
}

void PlayerData::SetInventory(Inventory inventory)
{
  _inventory = inventory;
}

}
