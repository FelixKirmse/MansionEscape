#include "View/TUI.h"

namespace MansionEscape
{

TUI::TUI(IController *controller)
  : _out(std::cout), _in(std::cin), _input('_'), _controller(controller)
{
}

int TUI::Execute()
{
  do
  {
    UpdateState();
    _in >> _input;
  }while(_input != 'q');
  return 0;
}

void TUI::UpdateState()
{
  if(_input == '_')
    return; // Optional: Logik fürs erste ausführen (z.B. laden des alten Spielstandes)
  // TUI Logik hier
}
}
