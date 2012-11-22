#include "View/TUI.h"
#include <boost/format.hpp>
#include <iostream>
#include "View/ITUIState.h"
#include "View/SelectActionState.h"

namespace MansionEscape
{
Coords const TUI::MansionEscapeLabelCoords(0, 0);
std::string const TUI::MansionEscape("MansionEscape");

TUI::TUI(IController* controller)
  : _controller(controller), _ncurses(),
    _currentState(&SelectActionState::GetInstance())
{ 
}

int TUI::Execute()
{
  bool continueExecution(true);
  do
  {
    _ncurses.ClearScreen();
    _ncurses.WriteAtCoords(MansionEscapeLabelCoords, MansionEscape);
    continueExecution = _currentState->Update(*this);
    _ncurses.UpdateScreen();
  }while(continueExecution);
  return 0;
}

NCursesWrapper& TUI::GetNCurses()
{
  return _ncurses;
}

void TUI::ChangeState(ITUIState* newState)
{
  _currentState = newState;
}

IController& TUI::GetController()
{
  return *_controller;
}

}
