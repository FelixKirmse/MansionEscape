#include "View/SelectActionState.h"
#include "View/TUI.h"
#include "View/NCursesWrapper.h"

namespace MansionEscape
{
#include "Include/SelectActionConstants.inc"

SelectActionState::SelectActionState()
{
}

SelectActionState& SelectActionState::GetInstance()
{
  static SelectActionState instance;
  return instance;
}

bool SelectActionState::Update(TUI& tui)
{

  return Action((char)getch(), tui);
}

bool SelectActionState::Action(char input, TUI& tui)
{
  IController& controller = tui.GetController();
  switch(keycode)
  {
  case 'w':
    controller.GoForward();
    break;
  case 'a':
    controller.TurnLeft();
    break;
  case 'd':
    controller.TurnRight();
    break;
  case 'e':
    controller;
    break;
  case 'i':
    break;
  case (char)27:
    return false;
  }
  return true;
}

void SelectActionState::Draw(TUI& tui)
{
  NCursesWrapper& nc = tui.GetNCurses();
  IController& controller = tui.GetController();
  bool roomChanged = controller.RoomChanged();

  nc.WriteAtCoords(RoomDescriptionCoords1,
                   roomChanged ?
                     controller.GetRoomDescription() :
                     controller.GetRoomViewDescription());
  if(roomChanged)
    nc.WriteAtCoords(RoomDescriptionCoords2,
                     controller.GetRoomViewDescription());

  nc.WriteAtCoords(FeedBackCoords, controller.GetFeedback());
  nc.WriteAtCoords(RoomLabelCoords, controller.GetRoomLabel());

  nc.WriteAtCoords(BaseMenuCoords, BaseMenuString);

  IController::ActionVec contextActions = controller.GetContextActions();

  if(contextActions.size() == 0)
    return;
  nc.WriteAtCoords(ContextAction3Coords, contextAction[0]);

  if(contextActions.size() == 1)
    return;
  nc.WriteAtCoords(ContextAction3Coords, contextAction[1]);

  if(contextActions.size() == 2)
    return;
  nc.WriteAtCoords(ContextAction3Coords, contextAction[2]);
}
}
