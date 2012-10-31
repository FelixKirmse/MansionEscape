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

  void AddItem(std::string const& label, Progress& progress);
  void RemoveItem(std::string const& label, Progress& progress);

private:
  ItemVec _items;
};
}
