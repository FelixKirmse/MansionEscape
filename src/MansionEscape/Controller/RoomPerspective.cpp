#include "Controller/RoomPerspective.h"
#include "Model/Progress.h"


namespace MansionEscape
{
RoomPerspective::RoomPerspective()
  : _contextActions(), _description("Invalid Room"), _nextRoom(""),
    _requiredFlagsForNextRoom(), _label("Invalid Room"),
    _pictureConditions(), _pictures()
{
}

bool RoomPerspective::CanAdvance(Progress const& progress) const
{
  for(auto& flag : _requiredFlagsForNextRoom)
    if(!progress.GetFlag(flag))
      return false;
  return true;
}

QPixmap const& RoomPerspective::GetPixMap(Progress const& progress) const
{
  for(size_t i = 0; i < _pictureConditions.size(); ++i)
  {
    if(CheckPictureFlags(progress, i))
      continue;
    return _pictures[i];
  }
  return _pictures.back(); // Default Bild immer am Ende
}

void RoomPerspective::LoadPictures()
{
  // TODO Bilder laden anhand der _pictureConditions
  // Default Bild am Ende anhängen!
}

bool RoomPerspective::CheckPictureFlags(Progress const& progress, size_t key) const
{
  for(auto& flag : _pictureConditions[key])
    if(!progress.GetFlag(flag))
      return false;
  return true;
}

std::string const& RoomPerspective::GetNextRoom() const
{
  return _nextRoom;
}

std::string const& RoomPerspective::GetDescription() const
{
  return _description;
}

std::string const& RoomPerspective::GetLabel() const
{
  return _label;
}

RoomPerspective::ActionVec const& RoomPerspective::GetContextActions() const
{
  return _contextActions;
}
}
