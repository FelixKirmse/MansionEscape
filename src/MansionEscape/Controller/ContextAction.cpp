#include "Controller/ContextAction.h"
#include "Model/Progress.h"
#include "Model/Inventory.h"

namespace MansionEscape
{
ContextAction::ContextAction()
  : _requiresFlags(), _grantsFlags(), _removesFlags(), _removesItems(),
    _grantsItems(), _reaction("Invalid Object")
{
}

bool ContextAction::CanPerform(Progress const& progress) const
{
  for(auto& flag : _requiresFlags)
    if(!progress.GetFlag(flag))
      return false;
  return true;
}

void ContextAction::Perform(Progress& progress, Inventory& inventory) const
{
  for(auto& flag : _grantsFlags)
    progress.SetFlag(flag, true);

  for(auto& flag : _removesFlags)
    progress.SetFlag(flag, false);

  for(auto& item : _removesItems)
    inventory.RemoveItemFromLabel(item);

  for(auto& item : _grantsItems)
    inventory.AddItemFromLabel(item);
}

std::string const& ContextAction::GetReaction() const
{
  return _label;
}

}
