#pragma once
#include <memory>
#include <vector>
#include <string>

// Iterator Design Pattern

namespace MansionEscape
{
class Item;
class Progress;

class Inventory
{
public:
  typedef std::vector<std::string> ItemVec;
  typedef ItemVec::iterator Iterator;
  typedef ItemVec::const_iterator ConstIterator;

  Iterator begin();
  ConstIterator begin() const;

  Iterator end();
  ConstIterator end() const;

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
