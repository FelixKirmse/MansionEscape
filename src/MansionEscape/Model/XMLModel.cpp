#include "Model/XMLModel.h"
#include <boost/filesystem.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <fstream>
#include "Model/XMLStorageFunctions.h"

namespace MansionEscape
{
std::string const XMLModel::XMLDir("~/.mansionescape/xml");
std::string const XMLModel::XMLFile("~/.mansionescape/xml/savedata.sav");

XMLModel::XMLModel()
  : BaseModel()
{
  using namespace boost::filesystem;
  path xmlDir(XMLDir);
  if(!exists(xmlDir))
    create_directory(xmlDir);
  std::fstream(XMLFile);
}

void XMLModel::Save()
{
  std::ofstream ofs(XMLFile);
  boost::archive::xml_oarchive oa(ofs);
  oa << boost::serialization::make_nvp("playerdata", GetPlayerData());
}

void XMLModel::Load()
{
  if(boost::filesystem::file_size(XMLFile) == 0u)
  {
    GetPlayerData() = PlayerData();
    return;
  }

  std::ifstream ifs(XMLFile);
  boost::archive::xml_iarchive ia(ifs);
  ia >> boost::serialization::make_nvp("playerdata", GetPlayerData());
}

void XMLModel::Delete()
{
  boost::filesystem::remove(XMLFile);
}
}
