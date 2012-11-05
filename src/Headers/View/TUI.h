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
  void DisplayMenu();
  void Clear();
  bool Update();
  bool MainMenuUpdate(char input);
  bool GameOptionUpdate(char input);
  bool MoveOptionsUpdate(char input);
  bool ItemListUpdate(char input);
  bool ItemListDetailUpdate(char input, Item item);
  void ReturnToMainMenu();

  std::ostream& _out;
  std::istream& _in;
  char _input;
  Item* _selectedItem;

  ControllerPtr _controller;

  enum
  {
    MainMenu,
    GameOptions,
    MoveOptions,
    ItemList,
    ItemDetailOptions
  } _menuState;

  bool _closeApp;

  static std::string const MainMenuText;
  static std::string const GameOptionsText;
  static std::string const MoveOptionsText;
  static std::string const WrongInputErrorText;
};
/*!\}*/
}
