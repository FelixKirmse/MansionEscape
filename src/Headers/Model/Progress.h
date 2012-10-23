#pragma once
#include <boost/unordered_map.hpp>

namespace MansionEscape
{
class RoomPerspective;

class Progress
{
public:
  typedef boost::unordered::unordered_map<Flag, bool> FlagMap;

  enum Flag
  {
    LOL,
    ROFL,
    LMAO,
    Hier,
    kommen,
    alle,
    flags,
    rein
  };

  Progress();
  bool GetFlag(Flag flag);
  void SetFlag(Flag flag, bool value);

private:
  FlagMap _flagMap;
};
}
