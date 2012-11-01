#include "Model/Inventory.h"
#include "Model/Progress.h"

namespace MansionEscape
{

Inventory::ItemVec const& Inventory::GetItems() const
{
  return _items;
}

Inventory::ItemVec& Inventory::GetItems()
{
  return _items;
}

void Inventory::AddItem(std::string const& label)
{
  _items.push_back(label);
  _progress->SetFlag("HAS" + label, true);
}

void Inventory::RemoveItem(std::string const& label)
{
  ItemVec::iterator pos(0);
  for(;pos != _items.end(); ++pos)
    if(*pos == label)
      break;
  _items.erase(pos);

  _progress->SetFlag("HAS" + label, false);
}

void Inventory::SetProgress(Progress* progress)
{
  _progress = progress;
}

}
