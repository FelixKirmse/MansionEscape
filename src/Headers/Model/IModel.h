#pragma once
#include <string>

namespace MansionEscape
{
/*!
  \addtogroup Model
  \{
*/
class PlayerData;
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

  virtual PlayerData& GetPlayerData() = 0;
};
/*!\}*/
}
