#pragma once
#include <string>
#include <qt4/QtGui/QPixmap>
#include <boost/serialization/serialization.hpp>
#include <boost/serialization/nvp.hpp>
#include <boost/format.hpp>
#include <qt4/QtCore/QString>

namespace MansionEscape
{
class ItemInfo
{
public:
  ItemInfo();

  std::string const& GetName() const;
  std::string const& GetCommentString() const;
  QPixmap const& GetPixMap() const;

private:
  friend class boost::serialization::access;

  template<class Archive>
  void save(Archive& ar, unsigned int const version) const;

  template<class Archive>
  void load(Archive& ar, unsigned int const version);

  std::string _name;
  std::string _commentString;
  QPixmap _picture;

  static std::string const ItemPicturePath;

  BOOST_SERIALIZATION_SPLIT_MEMBER()
};
#include "Inline/ItemInfo.inl"
}
