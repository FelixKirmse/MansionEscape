#include "View/TUI.h"
#include <boost/format.hpp>
#include <iostream>

namespace MansionEscape
{
#include "TUIConstants.inc"

TUI::TUI(IController *controller)
  : _out(std::cout), _in(std::cin), _input('_'), _controller(controller),  _menuState(MainMenu),
    _closeApp(false)
{
    Clear();
    DisplayMenu();
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

void TUI::Clear()
{
  std::cout << "\x1B[2J\x1B[H";
}

void TUI::UpdateState()
{
  if(_input == '_')
    return; // Optional: Logik fürs erste ausführen (z.B. laden des alten Spielstandes)
  // TUI Logik hier
}


void TUI::DisplayMenu()
{
  using namespace boost;
  using namespace std;

  switch(_menuState)
  {
    case MainMenu:
    cout << MainMenuText;
    break;

    case GameOptions:
    cout << GameOptionsText;
    break;

    case MoveOptions:
    cout << MoveOptionsText;
    break;
  }
  cout << endl << "Deine Auswahl: ";
}

bool TUI::Update()
{
  char input;
  std::cin >> input;
  switch(_menuState)
  {
  case MainMenu:
    return MainMenuUpdate(input);

  case GameOptions:
    return GameOptionUpdate(input);

  case MoveOptions:
    return MoveOptionsUpdate(input);

  case ItemList:
    return ItemListUpdate(input);

  default:
  return true;
  }
}


void TUI::ReturnToMainMenu()
{
  _menuState = MainMenu;
}

bool TUI::MainMenuUpdate(char input)
{
  switch (input)
  {
  case '1':
    // inspect room
    return true;

  case '2':
    _menuState = MoveOptions;
    return true;

  case '3':
    _menuState = ItemList;

  case 'o':
    _menuState = GameOptions;
    return true;

  default:
    return true;
  }
}

bool TUI::GameOptionUpdate(char input)
{
  using namespace boost;
  using namespace std;

  switch(input)
  {
    case '1':
      //do save
      return true;
    case '2':
      //do load
      return true;
    case '3':
      _closeApp = true;

    default:
      cout << WrongInputErrorText;
      break;

  }
}

bool TUI::MoveOptionsUpdate(char input)
{
  switch(input)
  {
    case 'v':
      //do vorwaerts
      return true;

    case 'l':
      //do links
      return true;

    case 'r':
      //do rechts
      return true;

    case 'a':
      ReturnToMainMenu();
      return true;

    default:
      break;
  }
}

bool TUI::ItemListUpdate(char input)
{
  switch(input)
  {
    /*
    case '1':
      _selectedItem = this;
    case '2':
    .
    .
    .

    */
    case 'a':
      ReturnToMainMenu();
      return true;
  }
}

}
