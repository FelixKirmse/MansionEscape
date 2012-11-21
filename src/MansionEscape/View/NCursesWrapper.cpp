#include "View/NCursesWrapper.h"

namespace MansionEscape
{
NCursesWrapper::NCursesWrapper()
{
  initscr();
  raw();
  nonl();
  keypad(stdscr, TRUE);
  noecho();
}

NCursesWrapper::~NCursesWrapper()
{
  endwin();
}

void NCursesWrapper::ClearScreen()
{
  erase();
}

void NCursesWrapper::UpdateScreen()
{
  refresh();
}

void NCursesWrapper::WriteAtCoords(Coords coords, std::string const& text)
{
  WriteAtCoords(coords.X, coords.Y, text);
}

void NCursesWrapper::WriteAtCoords(int x, int y, std::string const& text)
{
  mvaddstr(y, x, text.c_str());
}
}
