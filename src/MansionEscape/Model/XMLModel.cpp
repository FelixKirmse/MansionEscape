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
  oa << BOOST_SERIALIZATION_NVP(_playerData);
}

void XMLModel::Load()
{
  if(boost::filesystem::file_size(XMLFile) == 0u)
  {
    _playerData = PlayerData();
    return;
  }

  std::ifstream ifs(XMLFile);
  boost::archive::xml_iarchive ia(ifs);
  ia >> BOOST_SERIALIZATION_NVP(_playerData);
}

void XMLModel::Delete()
{
  boost::filesystem::remove(XMLFile);
}

PlayerData& XMLModel::GetPlayerData()
{
  return _playerData;
}


}
