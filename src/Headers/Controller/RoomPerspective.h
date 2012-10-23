#pragma once
#include <qt4/QtGui/QPixmap>
#include <string>
#include <boost/unordered_map.hpp>
#include <functional>
#include <array>
#include "Controller/ContextAction.h"

namespace MansionEscape
{
class Room;
enum Direction
{
  N,
  E,
  S,
  W
};

class RoomPerspective
{
public:
  typedef boost::unordered::unordered_map<std::string, QPixmap> StringPixMap;
  typedef std::array<ContextAction, 4> ContextArray;
  typedef std::function<QPixmap const&()> PixMapFunc;
  typedef std::function<bool()> GoForwardFunc;

  RoomPerspective(std::string label, Room* parent, PixMapFunc pixMapFunc,
                  GoForwardFunc forwardFunc = [](){return false;},
                  RoomPerspective* nextRoom = NULL);

  ContextArray const& GetContextActions() const;
  QPixmap const& GetCurrentPixMap() const;
  void GoForward();

private:
  std::string _label;
  StringPixMap _pictures;
  ContextArray _contextActions;
  PixMapFunc _getCurrentPixMap;
  Direction _currentDirection;
  Room* _parent;
  RoomPerspective* _nextRoom;
};
}
