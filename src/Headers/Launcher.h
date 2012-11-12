#pragma once
#include "GameOptions.h"
#include <string>

namespace MansionEscape
{
/*!
  \addtogroup Launcher
  \{
*/
/*!
 \brief Class used to display and manage the Launcher menu

 \class Launcher Launcher.h "src/Headers/Launcher.h"
*/
class Launcher
{
public:
/*!
 \brief Contructs the launcher and executes the Menu until the game is either started or the app closed

 \fn Launcher
*/
  Launcher();

  /*!
   \brief Gets the GameOptions that were selected in the Menu

   \fn GetOptions
   \return GameOptions
  */
  GameOptions GetOptions();

private:
  void Clear();
  bool Update();
  void DisplayMenu();

  bool MainMenuUpdate(char input);
  bool SaveDeleteUpdate(char input);
  bool SelectInterfaceUpdate(char input);
  bool SelectModelUpdate(char input);

  enum
  {
    MainMenu,
    SaveDelete,
    SelectInterface,
    SelectModel
  } _menuState;

  char _selectedInterface;
  char _selectedModel;
  bool _closeApp;

  static std::string const MainMenuText;
  static std::string const SaveDeleteText;
  static std::string const SelectInterfaceText;
  static std::string const SelectModelText;
  static std::string const GUI;
  static std::string const TUI;
  static std::string const DB;
  static std::string const XML;
};
/*!\}*/
}
