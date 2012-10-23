#pragma once
#include <memory>
#include <vector>

namespace MansionEscape
{
class Item;

class Inventory
{
public:
  typedef std::shared_ptr<Item> ItemPtr;
  typedef std::vector<ItemPtr> ItemVec;
};
}
