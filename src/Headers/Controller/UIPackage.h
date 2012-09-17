#pragma once
#include <vector>
#include <string>

namespace MansionEscape
{
class Room;
class Item;

/*!
 \brief Bundles all required data to display the current game state

 \struct UIPackage Controller/UIPackage.h
*/
struct UIPackage
{
  std::vector<Item> const& Inventory; /*!< Reference to the players inventory */
  std::string const& Feedback; /*!< Reference to the current feedback-string */
  Room const& CurrentRoom; /*!< This will change soon, UI don't need access to it */
};
}
