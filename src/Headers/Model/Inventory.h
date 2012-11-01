#pragma once
#include <memory>
#include <vector>
#include <string>

namespace MansionEscape
{
class Item;
class Progress;

class Inventory
{
public:
  typedef std::vector<std::string> ItemVec;

  ItemVec const& GetItems() const;
  ItemVec& GetItems();

  void AddItem(std::string const& label);
  void RemoveItem(std::string const& label);

  void SetProgress(Progress* progress);

private:
  ItemVec _items;
  Progress* _progress;
};
}
