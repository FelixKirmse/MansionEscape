#pragma once
#include "View/ITUIState.h"
#include "View/Coords.h"
#include <string>
#include "Controller/IController.h"

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

  bool Action(int input, TUI& tui);

  void Draw(TUI& tui);


  IController::ActionVec _contextActions;

  static Coords const RoomDescriptionCoords1; // Für RoomViewDescription, wenn RoomChanged() == false
  static Coords const RoomDescriptionCoords2; // Für RoomViewDescription, wenn RoomChanged() == true
  static Coords const FeedBackCoords;  

  static Coords const ContextAction1Coords;
  static Coords const ContextAction2Coords;
  static Coords const ContextAction3Coords;
  static Coords const BaseMenuCoords;

  static std::string const BaseMenuString;
};
}
