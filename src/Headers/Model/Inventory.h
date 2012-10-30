#pragma once
#include <memory>
#include <vector>
#include <string>

namespace MansionEscape
{
class Item;

class Inventory
{
public:
  typedef std::vector<Item*> ItemVec;

  ItemVec& GetItems() const;

  void AddItemFromLabel(std::string label);
  void RemoveItemFromLabel(std::string label);
};
}
