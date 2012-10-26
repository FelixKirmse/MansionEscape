#pragma once
#include "Model/IModel.h"
#include "Model/PlayerData.h"

namespace MansionEscape
{
/*!
  \addtogroup Model
  \{
*/
/*!
  \brief IModel implementation that saves data in XML-Format
  \class XMLModel Model/XMLModel.h
*/
class XMLModel : public IModel
{
public:
  XMLModel();

  void Save();
  void Load();
  void Delete();

  PlayerData& GetPlayerData();

private:
  PlayerData _playerData;

  static std::string const XMLDir;
  static std::string const XMLFile;
};
/*!\}*/
}
