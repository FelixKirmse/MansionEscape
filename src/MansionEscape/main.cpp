#include <qt4/QtGui/QApplication>
#include "View/GUI.h"
#include "View/TUI.h"
#include "Controller/Controller.h"
#include "Launcher.h"
#include "GameOptions.h"
#include <boost/filesystem.hpp>

int main(int argc, char** argv)
{
  using namespace std;
  using namespace MansionEscape;
  using namespace boost::filesystem;

  QApplication app(argc, argv);

  path profileDir("~/.mansionEscape");
  if(!exists(profileDir))
    create_directory(profileDir);

  Launcher launcher;
  GameOptions opts = launcher.GetOptions();
  if(opts.CloseApp)
    return 0;

  if(opts.Interface == 'g')
  {
    GUI gui(new Controller(opts.Model));
    gui.show();
    return app.exec();
  }

  TUI tui(new Controller(opts.Model));

  return tui.Execute();
}

/* Main zum testen von Item & Raumarchiven!
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <fstream>
#include <Model/Item.h>
#include <Controller/RoomPerspective.h>
#include <iostream>

int main(int argc, char** argv)
{
  using namespace MansionEscape;
  using namespace std;
  using namespace boost::archive;
  using namespace boost::serialization;

  QApplication app(argc, argv);

  RoomPerspective room;
  RoomPerspective::ActionVec contextActions;

  ContextAction action1;

  action1._grantsFlags = {"GRANTFLAG1" , "GRANTFLAG2", "GRANTFLAG3"};
  action1._grantsItems = {"GRANTITEM1", "GRANTITEM2", "GRANTITEM3"};
  action1._label = "ContextAction-Label - Volle ContextAction";
  action1._reaction = "Hier kommt die Reaktion rein.";
  action1._removesFlags = {"REMOVEFLAG1", "REMOVEFLAG2", "REMOVEFLAG3"};
  action1._removesItems = {"REMOVEITEM1", "REMOVEITEM2", "REMOVEITEM3"};
  action1._requiresFlags = {"REQUIRESFLAG1", "REQUIRESFLAG2", "REQUIRESFLAG3"};

  ContextAction action2;
  action2._label = "Beispiel für Leere KontextAction";
  action2._reaction = "Geht immer und nix passiert";

  contextActions.push_back(action1);
  contextActions.push_back(action2);

  room._contextActions = contextActions;
  room._requiredFlagsForNextRoom = {"NEXTROOMFLAG1", "NEXTROOMFLAG2"};
  room._pictureConditions = {{"PICFLAGCONDITION1_1", "PICFLAGCONDITION1_2"},{"PICFLAGCONDITION2_1", "PICFLAGCONDITION3_2"}};
  room._description = "Beschreibung des Raumes";
  room._label = "Label des Raumes";
  room._nextRoom = "Label des nächsten Raumes";

  ofstream ofs("roomexample.xml");
  xml_oarchive oa(ofs);
  oa << make_nvp("room", room);



  Item item;
  ItemInfo itemInfo;

  itemInfo._commentString = "Hier kommt der Comment hin!";
  itemInfo._name = "Hier kommt der Name hin!";
  item._itemInfo = itemInfo;

  ofstream ofs("itemexample.xml");
  xml_oarchive oa(ofs);

  oa << boost::serialization::make_nvp("item", item);



  Item loadItem;

  ifstream ifs("itemexample.xml");
  xml_iarchive ia(ifs);

  ia >> boost::serialization::make_nvp("item", loadItem);

  cout << loadItem.GetName() << endl << loadItem.GetCommentString() << endl;

  return 0;
}

*/
