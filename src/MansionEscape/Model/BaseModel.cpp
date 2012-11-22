#include "Model/BaseModel.h"

namespace MansionEscape
{
BaseModel::BaseModel()
  : _saveSlot(0), _playerData(), _assetHolder()
{
  _assetHolder.LoadAssets();
  _playerData.GetInventory().SetModel(this);
  _playerData.GetInventory().SetProgress(&_playerData.GetProgress());
}

void BaseModel::SetsaveSlot(int saveSlot)
{
  _saveSlot = saveSlot;
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

int BaseModel::GetSaveSlot()
{
  return _saveSlot;
}

void BaseModel::StartNewGame()
{
  _playerData = PlayerData();
  _playerData.GetInventory().SetModel(this);
  _playerData.GetInventory().SetProgress(&_playerData.GetProgress());
  _playerData.SetRoomLabel("START-N");
  Save();
}
}
