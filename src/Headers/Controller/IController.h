#pragma once
#include <vector>
#include <string>
#include <array>
#include <qt4/QtGui/QPixmap>

namespace MansionEscape
{
class Item;
class Inventory;
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
  typedef std::vector<ContextAction const*> ActionVec;
  typedef std::vector<Item const*> ItemVec;

  virtual ~IController() {} 
  virtual void GoForward() = 0;
  virtual void TurnLeft() = 0;
  virtual void TurnRight() = 0;
  virtual void PerformContextAction(ContextAction const& action) = 0;


  virtual std::string const& GetRoomLabel() const = 0;
  virtual std::string const& GetRoomDescription() const = 0;
  virtual std::string const& GetRoomInspectString() const = 0;
  virtual QPixmap const& GetRoomPicture() const = 0;

  virtual ActionVec GetContextActions() const = 0;
  virtual ItemVec GetInventoryItems() const = 0;
  virtual Item const& GetItemByName(std::string const& name) const = 0;

  virtual std::string const& GetFeedback() const = 0;
};
/*!\}*/
}
