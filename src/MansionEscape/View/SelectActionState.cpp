#include "View/SelectActionState.h"
#include "View/TUI.h"
#include "View/NCursesWrapper.h"
#include "Model/ContextAction.h"

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
  Draw(tui);
  return Action(tui.GetNCurses().GetKeyCode(), tui);
}

bool SelectActionState::Action(int input, TUI& tui)
{
  IController& controller = tui.GetController();
  switch((char)input)
  {
  case '1':
    if(_contextActions.size() > 0)
      controller.PerformContextAction(*_contextActions[0]);
    break;
  case '2':
    if(_contextActions.size() > 1)
      controller.PerformContextAction(*_contextActions[1]);
    break;
  case '3':
    if(_contextActions.size() > 2)
      controller.PerformContextAction(*_contextActions[2]);
    break;
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
    controller.InspectRoom();
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

  _contextActions = controller.GetContextActions();

  if(_contextActions.size() == 0)
    return;
  nc.WriteAtCoords(ContextAction1Coords,"(1)   " + _contextActions[0]->GetLabel());

  if(_contextActions.size() == 1)
    return;
  nc.WriteAtCoords(ContextAction2Coords,"(2)   " + _contextActions[1]->GetLabel());

  if(_contextActions.size() == 2)
    return;
  nc.WriteAtCoords(ContextAction3Coords,"(3)   " + _contextActions[2]->GetLabel());
}
}
