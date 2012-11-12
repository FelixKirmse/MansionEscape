#pragma once
#include <qt4/QtGui/QPixmap>
#include <vector>
#include <string>
#include <map>
#include "Model/ContextAction.h"
#include <boost/serialization/serialization.hpp>


namespace MansionEscape
{
class Progress;

class RoomView
{
public:
  typedef std::vector<ContextAction> ActionVec;
  typedef std::vector<std::string> FlagVec;
  typedef std::vector<FlagVec> FlagVecVec;
  typedef std::vector<QPixmap> PixVec;

  RoomView();

  bool CanAdvance(Progress& progress) const;
  QPixmap const& GetPixMap(Progress& progress) const;

  std::string const& GetNextRoom() const;
  std::string const& GetDescription() const;
  std::string const& GetViewLabel() const;
  std::string const& GetRoomLabel() const;
  std::string const& GetFailReaction() const;
  std::string const& GetInspectionString() const;
  std::string const& GetRoomDescription() const;
  ActionVec const& GetContextActions() const;

//private:
  friend class boost::serialization::access;

  template<class Archive>
  void save(Archive& ar, unsigned int const version) const;

  template<class Archive>
  void load(Archive& ar, unsigned int const version);

  void LoadPictures();
  bool CheckPictureFlags(Progress& progress, size_t key) const;

  ActionVec _contextActions;
  std::string _description;
  std::string _nextRoom;
  std::string _inspectionString;
  std::string _failReaction;
  std::string _roomDescription;
  FlagVec _requiredFlagsForNextRoom;

  std::string _label;
  std::string _roomLabel;

  FlagVecVec _pictureConditions;
  PixVec _pictures;

  static std::string const RoomPathFormatString;

  BOOST_SERIALIZATION_SPLIT_MEMBER();
};

#include "Inline/RoomView.inl"
}
