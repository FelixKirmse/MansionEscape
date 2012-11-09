#include "Controller/Controller.h"
#include "Model/ContextAction.h"
#include "Model/PlayerData.h"
#include "Model/RoomView.h"


namespace MansionEscape
{

Controller::Controller(IModel* model)
  : _model(model), _playerData(model->GetPlayerData())
{  
  _currentRoom = &_model->GetRoom(_playerData.GetRoomLabel());
  _playerData.GetInventory().SetProgress(&_playerData.GetProgress());
}

void Controller::ChangeRoom(std::string const& newRoom)
{
  _currentRoom = &_model->GetRoom(newRoom);
  _playerData.SetRoomLabel(newRoom);
}

void Controller::GoForward()
{  
  if(_currentRoom->CanAdvance(_playerData.GetProgress()))
    ChangeRoom(_currentRoom->GetNextRoom());
  else
    _feedBack = &_currentRoom->GetFailReaction();
  _model->Save();
}

void Controller::TurnLeft()
{  
  std::string const& viewLabel = _currentRoom->GetViewLabel();

  char dir = *viewLabel.rbegin();
  char append = dir == 'N' ? 'W' : dir == 'W' ? 'S' : dir == 'S' ? 'E' : 'N';

  ChangeRoom(_currentRoom->GetRoomLabel() + "-" + append);
  _model->Save();
}

void Controller::TurnRight()
{  
  std::string const& viewLabel = _currentRoom->GetViewLabel();

  char dir = *viewLabel.rbegin();
  char append = dir == 'N' ? 'E' : dir == 'E' ? 'S' : dir == 'S' ? 'W' : 'N';

  ChangeRoom(_currentRoom->GetRoomLabel() + "-" + append);
  _model->Save();
}

void Controller::PerformContextAction(ContextAction const& action)
{
  action.Perform(_playerData.GetProgress(), _playerData.GetInventory());
  _feedBack = &action.GetReaction();
  _model->Save();
}

std::string const& Controller::GetRoomLabel() const
{
  return _playerData.GetRoomLabel();
}

std::string const& Controller::GetRoomDescription() const
{
  return _currentRoom->GetDescription();
}

std::string const& Controller::GetRoomInspectString() const
{
  return _currentRoom->GetInspectionString();
}

QPixmap const& Controller::GetRoomPicture() const
{
  return _currentRoom->GetPixMap(_playerData.GetProgress());
}

Controller::ActionVec Controller::GetContextActions() const
{
  Controller::ActionVec availableActions;
  for(auto const& action : _currentRoom->GetContextActions())
  {
    if(action.CanPerform(_playerData.GetProgress()))
      availableActions.push_back(&action);
  }
  return availableActions;
}

Controller::ItemVec Controller::GetInventoryItems() const
{
  ItemVec items;
  for(auto const& label : _playerData.GetInventory())
  {
    items.push_back(&_model->GetItem(label));
  }
  return items;
}

Item const& Controller::GetItemByName(std::string const& name) const
{
  return _model->GetItem(name);
}

std::string const& Controller::GetFeedback() const
{
  return *_feedBack;
}

}
