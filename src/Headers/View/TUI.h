#pragma once
#include <iostream>
#include <memory>
#include "Controller/IController.h"

namespace MansionEscape
{
/*!
  \addtogroup View
  \{
*/
/*!
  \brief Provides a text-based UI to control the game
  \class TUI View/TUI.h
*/
class TUI
{
public:
  typedef std::unique_ptr<IController> ControllerPtr;

  TUI(IController* controller);
  int Execute();

private:
  void UpdateState();

  std::ostream& _out;
  std::istream& _in;
  char _input;

  ControllerPtr _controller;
};
/*!\}*/
}
