#include "Model/XMLModel.h"
#include <boost/filesystem.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <fstream>
#include "Model/XMLStorageFunctions.h"
#include <boost/format.hpp>

namespace MansionEscape
{
std::string const XMLModel::XMLDir("/.mansionescape/xml");
std::string const XMLModel::XMLFile("/.mansionescape/xml/savedata - %d.sav");

XMLModel::XMLModel()
  : BaseModel()
{
  using namespace boost::filesystem;
  path xmlDir(getenv("HOME") + XMLDir);
  if(!exists(xmlDir))
    create_directory(xmlDir);  
}

void XMLModel::Save()
{  
  std::ofstream ofs(GetCurrentSaveFilePath());
  boost::archive::xml_oarchive oa(ofs);
  oa << boost::serialization::make_nvp("playerdata", GetPlayerData());
}

void XMLModel::Load()
{
  std::string currentSaveFile(GetCurrentSaveFilePath());

  if(!boost::filesystem::exists(currentSaveFile))
  {
    StartNewGame();
    return;
  }

  std::ifstream ifs(currentSaveFile);
  boost::archive::xml_iarchive ia(ifs);
  ia >> boost::serialization::make_nvp("playerdata", GetPlayerData());
}

void XMLModel::Delete()
{  
  boost::filesystem::remove(GetCurrentSaveFilePath());
}

std::string XMLModel::GetCurrentSaveFilePath()
{
  boost::format xmlFile(XMLFile);
  xmlFile
      % GetSaveSlot();
  return xmlFile.str();
}
}
