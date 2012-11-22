#pragma once
#include <string>
#include "View/ITUIState.h"

namespace MansionEscape
{
class CompassState : public ITUIState
{
public:
  static CompassState& GetInstance();

  bool Update(TUI& tui);

private:
  CompassState();

  static std::string const CompassNorth;
  static std::string const CompassEast;
  static std::string const CompassWest;
  static std::string const CompassSouth;
};
}
