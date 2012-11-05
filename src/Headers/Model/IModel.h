#pragma once
#include <string>

namespace MansionEscape
{
/*!
  \addtogroup Model
  \{
*/
class PlayerData;
class Item;
class RoomView;
/*!
  \brief Interface that exposes functions for saving and loading data
  \interface IModel Model/IModel.h
*/
class IModel
{
public:
  virtual ~IModel(){}

  virtual void Save() = 0;
  virtual void Load() = 0;
  virtual void Delete() = 0;

  virtual Item const& GetItem(std::string const& name) = 0;
  virtual RoomView const& GetRoom(std::string const& label) = 0;

  virtual PlayerData& GetPlayerData() = 0;
};
/*!\}*/
}
