#pragma once
#include <array>
#include <string>
#include <qt4/QtGui/QPixmap>
#include <boost/unordered_map.hpp>

namespace MansionEscape
{
struct ContextAction;

/*!
 \brief The Room class. \n
 This class is currently changes heavily and fast.

 \class Room Controller/Room.h
*/
class Room
{
public:  
  typedef std::array<ContextAction const*, 3> ContextArray;
  typedef std::array<QPixmap const*, 4> ImageArray;
  typedef boost::unordered::unordered_map<Direction, ImageArray> ImageMap;

  /*!
   \brief

  */
  enum Direction
  {
    North,
    West,
    South,
    East
  };

  /*!
   \brief

   \return ContextArray const&
  */
  ContextArray const& GetContextActions() const;
  /*!
   \brief

   \return QPixmap const&
  */
  QPixmap const& GetImage() const;
  /*!
   \brief

   \return std::string const&
  */
  std::string const& GetRoomDescription() const;

private:
  ContextArray _contextActions; /*!< TODO */
  ImageMap _imageMap; /*!< TODO */
  std::string _roomDescription; /*!< TODO */
};
}
