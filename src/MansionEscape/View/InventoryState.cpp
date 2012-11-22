#include "View/InventoryState.h"
#include "View/TUI.h"
#include <sstream>
#include "Model/Item.h"
#include "View/SelectActionState.h"

namespace MansionEscape
{
#include "Include/InventoryStateConstants.inc"

InventoryState::InventoryState()
  : _inventory(), _page(1), _commentString(0)
{
}

InventoryState& InventoryState::GetInstance()
{
  static InventoryState instance;
  return instance;
}

bool InventoryState::Update(TUI& tui)
{
  Draw(tui);
  return Action(tui.GetNCurses().GetKeyCode(), tui);
}

bool InventoryState::Action(int input, TUI& tui)
{
  switch((char)input)
  {
  case 'a':
    _page = (_page > 1) ? _page - 1 : 1;
    break;
  case 'd':
    _page = (_page < GetMaxPage() ? _page + 1 : GetMaxPage());
    break;
  case 'i':
    tui.ChangeState(&SelectActionState::GetInstance());
    break;
  default:
    int index = ((char)input - '0') - 1;
    if(index < 0 || (size_t)index >= ItemsPerPage || (size_t)(index * _page) >= _inventory.size())
      break;
    _commentString = &_inventory[(size_t)index * _page]->GetCommentString();
    break;
  }
  return true;
}

void InventoryState::Draw(TUI& tui)
{
  IController& controller = tui.GetController();
  NCursesWrapper& nc = tui.GetNCurses();

  _inventory = controller.GetInventoryItems();
  size_t index = (_page - 1) * ItemsPerPage;
  std::stringstream itemList;
  itemList << "Wähle das Item, dass du näher untersuchen möchtest:\n";
  itemList << "Seite " << _page << "/" << GetMaxPage() << "\n";
  for(size_t counter = 0;
      counter < ItemsPerPage && index < _inventory.size();
      ++index, ++counter)
  {
    itemList << "(" << (index%ItemsPerPage) + 1  << ")   " << _inventory[index]->GetName() << "\n";
  }

  nc.WriteAtCoords(ListStartCoords, itemList.str());
  nc.WriteAtCoords(CommentCoords, _commentString == 0 ? "" : *_commentString);
  nc.WriteAtCoords(MenuCoords, MenuString);
  _commentString = 0;
}

int InventoryState::GetMaxPage()
{
  return (_inventory.size() / ItemsPerPage) + 1;
}


}
