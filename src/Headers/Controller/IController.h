#pragma once
#include <vector>
#include <string>
#include <array>

namespace MansionEscape
{
class Item;
class Inventory;
struct UIPackage;
struct ContextAction;

/*!
 \addtogroup Controller
 \{
*/
/*!
 \brief Interface that exposes functions to control game state

 \interface IController Controller/IController.h
*/
class IController
{
public:
  virtual ~IController() {}

  /*!
   \brief Retrieves the reference to the current UIPackage.

    Should be used after using any other functions of this interface
    to get an updated state of the game.

   \return UIPackage const&
  */
  virtual UIPackage const& GetUIPackage() const = 0;

  /*!
   \brief Attempt to advance to the next room by going in the current direction.

  */
  virtual void GoForward() = 0;
  /*!
   \brief Turn left.

  */
  virtual void TurnLeft() = 0;
  /*!
   \brief Turn right.

  */
  virtual void TurnRight() = 0;

  /*!
   \brief Attempt to use an Item.

   \param item The Item to use
  */
  virtual void UseItem(Item const& item) = 0;
  /*!
   \brief Make a comment about an Item.

   \param item The Item to comment on.
  */
  virtual void CommentOnItem(Item const& item) = 0;

  /*!
   \brief Inspect the your current FoV more thouroughly to potentially unlock more ContextActions.

  */
  virtual void Inspect() = 0;
  /*!
   \brief Attempt to perform a ContextAction.

   \param action The ContextAction to perform.
  */
  virtual void PerformContextAction(ContextAction action) = 0;
};
/*!\}*/
}
