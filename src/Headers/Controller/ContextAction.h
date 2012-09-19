#pragma once

namespace MansionEscape
{
class Item;

/*!
 \addtogroup Controller
 \{
*/
/*!
 \brief Struct that associates a context to an item, allowing for multiple interaction types with the environment.

 \struct ContextAction Controller/ContextAction.h
*/
struct ContextAction
{
/*!
 \brief The type of context to use the item in.

*/
  enum Type
  {
    Use,
    Take
  } ContextType; /*!< What you want to do with the item.\n NOTE: The \a Use ContextType is not used to use an item in your inventory, but rather to use an environmental item in the room.*/
  Item const& ContextItem; /*!< The Item to perform the action on/with. */
};
/*!\}*/
}
