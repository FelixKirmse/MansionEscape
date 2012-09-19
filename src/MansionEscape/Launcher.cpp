#include "Launcher.h"
#include <boost/format.hpp>
#include <iostream>
#include "Model/XMLModel.h"
#include "Model/DBModel.h"

namespace MansionEscape
{
#include "LauncherConstants.inc"

Launcher::Launcher()
  : _menuState(MainMenu), _selectedInterface('g'), _selectedModel('x'),
    _closeApp(false)
{
  do
  {
    Clear();
    DisplayMenu();
  } while(Update());
}

GameOptions Launcher::GetOptions()
{
  IModel* modelPtr;
  if(_selectedModel == 'x')
    modelPtr = new XMLModel();
  else
    modelPtr = new DBModel();

  return
  {
      _selectedInterface,
      modelPtr,
      _closeApp
  };
}

void Launcher::Clear()
{
  std::cout << "\x1B[2J\x1B[H";
}

void Launcher::DisplayMenu()
{
  using namespace boost;
  using namespace std;

  switch(_menuState)
  {
  case MainMenu:
  {
    format mainMenu(MainMenuText);
    mainMenu
        % (_selectedInterface == 'g' ? GUI : TUI)
        % (_selectedModel == 'x' ? XML : DB);
    cout << mainMenu.str();
    break;
  }

  case SaveDelete:
    cout << SaveDeleteText;
    break;

  case SelectInterface:
    cout << SelectInterfaceText;
    break;

  case SelectModel:
    cout << SelectModelText;
    break;
  }

  cout << endl << "Ihre Auswahl: ";
}

bool Launcher::Update()
{
  char input;
  std::cin >> input;
  switch(_menuState)
  {
  case MainMenu:
    return MainMenuUpdate(input);

  case SaveDelete:
    return SaveDeleteUpdate(input);

  case SelectInterface:
    return SelectInterfaceUpdate(input);

  case SelectModel:
    return SelectModelUpdate(input);
  }
  return true;
}

bool Launcher::MainMenuUpdate(char input)
{
  switch(input)
  {
  case 'a':
    return false;

  case 'b':
    _menuState = SaveDelete;
    return true;

  case 'c':
    _menuState = SelectInterface;
    return true;

  case 'd':
    _menuState = SelectModel;
    return true;

  case 'q':
    _closeApp = true;
    return false;

  default:
    return true;
  }
}

bool Launcher::SaveDeleteUpdate(char input)
{
  switch(input)
  {
  case 'a':
    // TODO XML Spielstand löschen
    break;
  case 'b':
    // TODO DB Spielstand löschen
    break;

  case 'q':
    _menuState = MainMenu; //Fallthrough intended

  default:
    return true;
  }
  _menuState = MainMenu;
  return true;
}

bool Launcher::SelectInterfaceUpdate(char input)
{
  switch(input)
  {
  case 'g': //Fallthrough intended
  case 't':
    _selectedInterface = input; //Fallthrough intended

  case 'q':
    _menuState = MainMenu; //Fallthrough intended
  default:
    return true;
  }
}

bool Launcher::SelectModelUpdate(char input)
{
  switch(input)
  {
  case 'd': //Fallthrough intended
  case 'x':
    _selectedModel = input; //Fallthrough intended

  case 'q':
    _menuState = MainMenu; //Fallthrough intended

  default:
    return true;
  }
}

}
