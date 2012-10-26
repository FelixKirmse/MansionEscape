#pragma once
#include <string>
#include <qt4/QtGui/QPixmap>

namespace MansionEscape
{
class Item
{
public:
  Item(std::string const& label);
  std::string const& GetLabel() const;
  void LoadItemFromLabel(std::string const& label);

private:
  std::string _label;
  QPixmap _picture;
  std::string _description;
};
}
