#pragma once
#include <qt4/QtGui/QPixmap>
#include <vector>
#include <string>
#include <map>
#include "Controller/ContextAction.h"
#include <boost/serialization/serialization.hpp>


namespace MansionEscape
{
class Progress;

class RoomPerspective
{
public:
  typedef std::vector<ContextAction> ActionVec;
  typedef std::vector<std::string> FlagVec;
  typedef std::vector<FlagVec> FlagVecVec;
  typedef std::vector<QPixmap> PixVec;

  RoomPerspective();

  bool CanAdvance(Progress const& progress) const;
  QPixmap const& GetPixMap(Progress const& progress) const;

  std::string const& GetNextRoom() const;
  std::string const& GetDescription() const;
  std::string const& GetLabel() const;
  ActionVec const& GetContextActions() const;

private:
  friend class boost::serialization::access;

  template<class Archive>
  void save(Archive& ar, unsigned int const version) const;

  template<class Archive>
  void load(Archive& ar, unsigned int const version);

  void LoadPictures();
  bool CheckPictureFlags(Progress const& progress, size_t key) const;

  ActionVec _contextActions;
  std::string _description;
  std::string _nextRoom;
  FlagVec _requiredFlagsForNextRoom;

  std::string _label;

  FlagVecVec _pictureConditions;
  PixVec _pictures;

  BOOST_SERIALIZATION_SPLIT_MEMBER();
};

#include "Inline/RoomPerspective.inl"
}
