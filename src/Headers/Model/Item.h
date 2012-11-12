#pragma once
#include <string>
#include <qt4/QtGui/QPixmap>
#include "Model/ItemInfo.h"
#include <boost/serialization/serialization.hpp>
#include <boost/serialization/nvp.hpp>

namespace MansionEscape
{
class Item
{
public:
  Item();

  std::string const& GetName() const;
  std::string const& GetCommentString() const;
  QPixmap const& GetPixMap() const;

//private:
  friend class boost::serialization::access;
  template<class Archive>
  void serialize(Archive& ar, unsigned int const version);

  ItemInfo _itemInfo;
};

#include "Inline/Item.inl"
}
