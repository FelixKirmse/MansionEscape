#pragma once
#include <vector>
#include <string>

namespace MansionEscape
{
class Room;
class Item;

/*!
 \brief SchnuckelWuckel

 \struct UIPackage Controller/UIPackage.h
*/
struct UIPackage
{
  std::vector<Item> const& Inventory; /*!< TODO */
  std::string const& Feedback; /*!< TODO */
  Room const& CurrentRoom; /*!< TODO */
};
}
