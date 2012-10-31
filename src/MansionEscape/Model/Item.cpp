#include "Model/Item.h"

namespace MansionEscape
{
Item::Item()
  : _itemInfo()
{
}

std::string const& Item::GetName() const
{
  return _itemInfo.GetName();
}

std::string const& Item::GetCommentString() const
{
  return _itemInfo.GetCommentString();
}

QPixmap const& Item::GetPixMap() const
{
  return _itemInfo.GetPixMap();
}
}
