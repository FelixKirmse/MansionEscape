#pragma once
#include <memory>
#include <vector>
#include <string>

// Iterator Design Pattern...nicht wirklich

namespace MansionEscape
{
class Item;
class Progress;
class IModel;

class Inventory
{
public:
  typedef std::vector<Item const*> ItemVec;
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
  void SetModel(IModel* model);
  IModel* GetModel();

private:
  ItemVec _items;
  Progress* _progress;
  IModel* _model;
};
}
