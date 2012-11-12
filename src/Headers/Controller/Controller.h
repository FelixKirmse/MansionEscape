#pragma once
#include "Controller/IController.h"
#include "Model/IModel.h"
#include <memory>

namespace MansionEscape
{
class RoomView;

/*!
  \addtogroup Controller
  \{
*/
/*!
  \brief Controls game state

  \class Controller Controller/Controller
*/
class Controller : public IController
{
public:
  typedef std::unique_ptr<IModel> ModelPtr;

  Controller(IModel* model);

  /* IController Functions Start */
  void GoForward();
  void TurnLeft();
  void TurnRight();
  void PerformContextAction(ContextAction const& action);


  std::string const& GetRoomLabel() const;
  std::string const& GetRoomViewDescription() const;
  bool RoomChanged() const;
  std::string const& GetRoomDescription() const;
  std::string const& GetRoomInspectString() const;
  QPixmap const& GetRoomPicture() const;


  ActionVec GetContextActions() const;
  ItemVec GetInventoryItems() const;

  Item const& GetItemByName(std::string const& name) const;
  std::string const& GetFeedback() const;
  /* IController Functions End */

private:
  void ChangeRoom(std::string const& newRoom);

  ModelPtr _model;  
  PlayerData& _playerData;
  std::string const* _feedBack;
  RoomView const* _currentRoom;
  bool _changedRoom;
};
/*!\}*/
}
