#include "View/CompassState.h"
#include "View/TUI.h"
#include "View/SelectActionState.h"

namespace MansionEscape
{
#include "Include/CompassStateConstants.inc"

CompassState::CompassState()
{
}

CompassState& CompassState::GetInstance()
{
  static CompassState instance;
  return instance;
}

bool CompassState::Update(TUI& tui)
{
  NCursesWrapper& nc = tui.GetNCurses();
  switch(tui.GetController().GetDirection())
  {
  case 'N':
    nc.WriteAtCoords(13, 0, CompassNorth);
    break;
  case 'E':
    nc.WriteAtCoords(13, 0, CompassEast);
    break;
  case 'S':
    nc.WriteAtCoords(13, 0, CompassSouth);
    break;
  case 'W':
    nc.WriteAtCoords(13, 0, CompassWest);
    break;
  default:
    break;
  }

  int code = tui.GetNCurses().GetKeyCode();
  if((char)code == 'c' || code == 27)
    tui.ChangeState(&SelectActionState::GetInstance());
  return true;
}

}
