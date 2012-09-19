#include "View/GUI.h"

namespace MansionEscape
{

GUI::GUI(IController* controller)
  : QMainWindow(0),
    _ui(new Ui::GUI),
    _controller(controller)
{
  _ui->setupUi(this);
}


void GUI::on_TestButton_pressed()
{
  _ui->label->setText("Well Done!");
}
}


