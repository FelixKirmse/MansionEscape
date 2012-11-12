#include "Model/ItemInfo.h"

namespace MansionEscape
{
std::string const ItemInfo::ItemPicturePath("contents/items/%s/%s.png");

ItemInfo::ItemInfo()
  : _name("Invalid Item"), _commentString("Invalid Item"), _picture()
{
}

std::string const& ItemInfo::GetName() const
{
  return _name;
}

std::string const& ItemInfo::GetCommentString() const
{
  return _commentString;
}

QPixmap const& ItemInfo::GetPixMap() const
{
  return _picture;
}
}
