#pragma once
#include <cstddef>

namespace MansionEscape
{
struct Coords
{
  Coords(int x, int y)
    : X(x), Y(y)
  {
  }

  int X;
  int Y;
};
}
