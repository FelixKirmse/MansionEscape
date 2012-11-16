#pragma once
#include "Model/BaseModel.h"
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
class XMLModel : public BaseModel
{
public:
  XMLModel();

  void Save();
  void Load();
  void Delete(); 

private:
  std::string GetCurrentSaveFilePath();

  static std::string const XMLDir;
  static std::string const XMLFile;
};
/*!\}*/
}
