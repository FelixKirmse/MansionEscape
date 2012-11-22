#pragma once
#include "View/ITUIState.h"
#include "Controller/IController.h"
#include "View/Coords.h"

namespace MansionEscape
{
class InventoryState : public ITUIState
{
public:
  static InventoryState& GetInstance();

  bool Update(TUI& tui);

private:
  InventoryState();

  int GetMaxPage();
  bool Action(int input, TUI& tui);
  void Draw(TUI& tui);

  IController::ItemVec _inventory;
  int _page;
  std::string const* _commentString;

  static size_t const ItemsPerPage;
  static Coords const ListStartCoords;
  static Coords const CommentCoords;
  static Coords const MenuCoords;

  static std::string const MenuString;
};
}
