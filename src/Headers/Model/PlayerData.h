#pragma once
#include <string>
#include "Model/Progress.h"
#include "Model/Inventory.h"

namespace MansionEscape
{
class PlayerData
{
public:
  Progress& GetProgress();
  Inventory& GetInventory();

  Progress const& GetProgress() const;
  Inventory const& GetInventory() const;
  std::string const& GetRoomLabel() const;

  void SetProgress(Progress progress);
  void SetInventory(Inventory inventory);
  void SetRoomLabel(std::string const& roomLabel);

private:
  Progress _progress;
  Inventory _inventory;
  std::string _roomLabel;
};
}
