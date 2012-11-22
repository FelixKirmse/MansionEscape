#include "View/NCursesWrapper.h"

namespace MansionEscape
{
NCursesWrapper::NCursesWrapper()
{
  setlocale(LC_CTYPE, "C-UTF-8");
  initscr();
  raw();
  nonl();
  keypad(stdscr, TRUE);
  noecho();
  curs_set(0);
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

int NCursesWrapper::GetKeyCode()
{
  return getch();
}

void NCursesWrapper::SubscribeToOnClickEvents()
{
  mousemask(ALL_MOUSE_EVENTS, 0);
}

bool NCursesWrapper::MouseClicked(int keycode)
{
  if(keycode != KEY_MOUSE)
    return false;
  getmouse(&_mouseEvent);
  return true;
}

Coords NCursesWrapper::GetMousePosition()
{
  return Coords(_mouseEvent.x, _mouseEvent.y);
}
}
