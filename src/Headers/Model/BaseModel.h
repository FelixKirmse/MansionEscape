#pragma once
#include "Model/IModel.h"
#include "Model/AssetHolder.h"
#include "Model/PlayerData.h"

namespace MansionEscape
{
class BaseModel : public IModel
{
public:
  ~BaseModel() {}

  virtual void Save() = 0;
  virtual void Load() = 0;
  virtual void Delete() = 0;

  void SetsaveSlot(int saveSlot);
  PlayerData& GetPlayerData();
  Item const& GetItem(std::string const& name);
  RoomView const& GetRoom(std::string const& label);
  int GetSaveSlot();
  void StartNewGame();

protected:
  BaseModel();

private:
  int _saveSlot;
  PlayerData _playerData;
  AssetHolder _assetHolder;
};
}
