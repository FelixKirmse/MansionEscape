#pragma once
#include <iostream>
#include <memory>
#include "Controller/IController.h"
#include "View/NCursesWrapper.h"

// State Design Pattern

namespace MansionEscape
{
class ITUIState;

class TUI
{
public:
  typedef std::unique_ptr<IController> ControllerPtr;

  TUI(IController* controller);
  int Execute();

  NCursesWrapper& GetNCurses();
  void ChangeState(ITUIState* newState);
  IController& GetController();

private:  
  ControllerPtr _controller; 
  NCursesWrapper _ncurses;
  ITUIState* _currentState;

  static Coords const MansionEscapeLabelCoords;
  static std::string const MansionEscape;
};
}
