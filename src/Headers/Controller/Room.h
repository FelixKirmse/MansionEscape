#pragma once
#include <string>
#include "Controller/RoomPerspective.h"

namespace MansionEscape
{
class Room
{
public:
  Room(std::string label); 

  void GoForward();
  void TurnLeft();
  void TurnRight();

private:
  std::string _label;

  RoomPerspective* _activeRoom;

  RoomPerspective _north;
  RoomPerspective _south;
  RoomPerspective _east;
  RoomPerspective _west;
};
}
