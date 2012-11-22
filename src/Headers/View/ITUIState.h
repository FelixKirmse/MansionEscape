#pragma once

namespace MansionEscape
{
class TUI;

class ITUIState
{
public:
  virtual ~ITUIState() {}

  virtual bool Update(TUI& tui) = 0;
};
}
