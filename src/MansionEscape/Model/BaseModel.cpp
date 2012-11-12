#include "Model/BaseModel.h"

namespace MansionEscape
{
BaseModel::BaseModel()
  : _playerData(), _assetHolder()
{
  _assetHolder.LoadAssets();
}

PlayerData& BaseModel::GetPlayerData()
{
  return _playerData;
}

Item const& BaseModel::GetItem(std::string const& name)
{
  return _assetHolder.GetItem(name);
}

RoomView const& BaseModel::GetRoom(std::string const& label)
{
  return _assetHolder.GetRoom(label);
}
}
