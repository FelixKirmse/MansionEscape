#include "Model/Inventory.h"
#include "Model/Progress.h"

namespace MansionEscape
{

Inventory::ItemVec const& Inventory::GetItems() const
{
  return _items;
}

void Inventory::AddItem(std::string const& label, Progress& progress)
{
  _items.push_back(label);
  progress.SetFlag("HAS" + label, true);
}

void Inventory::RemoveItem(std::string const& label, Progress& progress)
{
  int pos(0);
  for(;pos < _items.size(); ++pos)
    if(_items[pos] == label)
      break;
  _items.erase(pos);

  progress.SetFlag("HAS" + label, false);
}

}
