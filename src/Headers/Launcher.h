#pragma once
#include "GameOptions.h"
#include <string>

namespace MansionEscape
{
class Launcher
{
public:
  Launcher();  
  GameOptions GetOptions();

private:
  void Clear();
  bool Update();
  void DisplayMenu();

  bool MainMenuUpdate(char input);
  bool SaveDeleteUpdate(char input);
  bool SelectInterfaceUpdate(char input);
  bool SelectModelUpdate(char input);
  bool SelectSaveSlotUpdate(char input);

  enum
  {
    MainMenu,
    SaveDelete,
    SelectInterface,
    SelectModel,
    SelectSaveSlot
  } _menuState;

  char _selectedInterface;
  char _selectedModel;
  int _saveSlot;
  bool _closeApp;

  static std::string const MainMenuText;
  static std::string const SaveDeleteText;
  static std::string const SelectInterfaceText;
  static std::string const SelectModelText;
  static std::string const SaveSlotText;
  static std::string const GUI;
  static std::string const TUI;
  static std::string const DB;
  static std::string const XML;
};
}
