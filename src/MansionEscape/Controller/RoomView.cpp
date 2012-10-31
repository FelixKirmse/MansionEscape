#include "Controller/RoomView.h"
#include "Model/Progress.h"


namespace MansionEscape
{
RoomView::RoomView()
  : _contextActions(), _description("Invalid Room"), _nextRoom(""),
    _inspectionString("Invalid Room"),
    _failReaction("Ich kann nicht durch Wände gehen..."),
    _requiredFlagsForNextRoom(), _label("Invalid Room"),
    _roomLabel("Invalid Room"),
    _pictureConditions(), _pictures()
{
}

bool RoomView::CanAdvance(Progress& progress) const
{
  for(auto& flag : _requiredFlagsForNextRoom)
    if(!progress.GetFlag(flag))
      return false;
  return _nextRoom != ""; // Man kann nur advancen, wenn ein _nextRoom gesetzt ist.
}

QPixmap const& RoomView::GetPixMap(Progress& progress) const
{
  for(size_t i = 0; i < _pictureConditions.size(); ++i)
  {
    if(CheckPictureFlags(progress, i))
      continue;
    return _pictures[i];
  }
  return _pictures.back(); // Default Bild immer am Ende
}

void RoomView::LoadPictures()
{
  // TODO Bilder laden anhand der _pictureConditions
  // Default Bild am Ende anhängen!
}

bool RoomView::CheckPictureFlags(Progress& progress, size_t key) const
{
  for(auto& flag : _pictureConditions[key])
    if(!progress.GetFlag(flag))
      return false;
  return true;
}

std::string const& RoomView::GetNextRoom() const
{
  return _nextRoom;
}

std::string const& RoomView::GetDescription() const
{
  return _description;
}

std::string const& RoomView::GetViewLabel() const
{
  return _label;
}

RoomView::ActionVec const& RoomView::GetContextActions() const
{
  return _contextActions;
}

std::string const& RoomView::GetInspectionString() const
{
  return _inspectionString;
}

std::string const& RoomView::GetRoomLabel() const
{
  return _roomLabel;
}

std::string const& RoomView::GetFailReaction() const
{
  return _failReaction;
}
}

