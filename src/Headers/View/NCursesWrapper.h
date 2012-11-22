#pragma once
#include <ncurses.h>
#include "View/Coords.h"
#include <string>

// Wrapper Design-Pattern

namespace MansionEscape
{
class NCursesWrapper
{
public:
  NCursesWrapper();
  ~NCursesWrapper();

  void WriteAtCoords(Coords coords, std::string const& text);
  void WriteAtCoords(int x, int y, std::string const& text);

  void ClearScreen();
  void UpdateScreen();

  int GetKeyCode();
  Coords GetMousePosition();
  void SubscribeToOnClickEvents();
  bool MouseClicked(int keycode);

private:
  MEVENT _mouseEvent;
};
}
