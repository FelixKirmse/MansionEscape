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
  Iterator pos(0);
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

Inventory::Iterator Inventory::begin()
{
  return _items.begin();
}

Inventory::ConstIterator Inventory::begin() const
{
  return _items.begin();
}

Inventory::Iterator Inventory::end()
{
  return _items.end();
}

Inventory::ConstIterator Inventory::end() const
{
  return _items.end();
}



}
