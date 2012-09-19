#include <qt4/QtGui/QApplication>
#include "View/GUI.h"
#include "View/TUI.h"
#include "Controller/Controller.h"
#include "Launcher.h"
#include "GameOptions.h"

int main(int argc, char** argv)
{
  using namespace std;
  using namespace MansionEscape;

  Launcher launcher;
  GameOptions opts = launcher.GetOptions();
  if(opts.CloseApp)
    return 0;

  if(opts.Interface == 'g')
  {
    QApplication app(argc, argv);
    GUI gui(new Controller(opts.Model));
    gui.show();
    return app.exec();
  }

  TUI tui(new Controller(opts.Model));

  return tui.Execute();
}
