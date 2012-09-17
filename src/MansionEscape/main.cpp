#include <iostream>
#include <qt4/QtCore/QLibraryInfo>
#include <qt4/QtCore/QString>
#include "Controller/IController.h"

int main(int argc, char** argv)
{
  std::cout << QLibraryInfo::location(QLibraryInfo::PluginsPath).toStdString() << std::endl;
  return 0;
}
