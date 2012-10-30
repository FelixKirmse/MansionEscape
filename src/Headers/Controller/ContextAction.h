#pragma once
#include <vector>
#include <string>
#include <boost/serialization/serialization.hpp>
#include <boost/serialization/vector.hpp>

namespace MansionEscape
{
class Progress;
class Inventory;

class ContextAction
{
public:
  typedef std::vector<std::string> StringVec;

  ContextAction();

  bool CanPerform(Progress const& progress) const;
  void Perform(Progress& progress, Inventory& inventory) const;
  std::string const& GetReaction() const;

private:
  friend class boost::serialization::access;
  template<class Archive>
  void serialize(Archive& ar, unsigned int const version);

  StringVec _requiresFlags;
  StringVec _grantsFlags;
  StringVec _removesFlags;

  StringVec _removesItems;
  StringVec _grantsItems;

  std::string _reaction;
  std::string _label;
};

#include "Inline/ContextAction.inl"
}
