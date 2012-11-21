#pragma once
#include "View/ITUIState.h"
#include "View/Coords.h"
#include <string>

// Memory-Safe Singleton Pattern

namespace MansionEscape
{
class SelectActionState : public ITUIState
{
public:
  static SelectActionState& GetInstance();

  bool Update(TUI& tui);

private:
  SelectActionState();

  bool Action(int keycode, TUI& tui);
  void Draw(TUI& tui);

  static Coords const RoomDescriptionCoords1; // Für RoomViewDescription, wenn RoomChanged() == false
  static Coords const RoomDescriptionCoords2; // Für RoomViewDescription, wenn RoomChanged() == true
  static Coords const FeedBackCoords;
  static Coords const RoomLabelCoords;

  static Coords const ContextAction1Coords;
  static Coords const ContextAction2Coords;
  static Coords const ContextAction3Coords;
  static Coords const BaseMenuCoords;

  static std::string const BaseMenuString;
};
}
