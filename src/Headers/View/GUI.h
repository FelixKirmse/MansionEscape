#pragma once
#include <qt4/QtGui/QMainWindow>
#include <qt4/QtGui/QListWidgetItem>
#include <memory>
#include "View/ui_GUI.h"
#include "Controller/IController.h"

/*!\cond*/
namespace Ui {class GUI;}
/*!\endcond*/

namespace MansionEscape
{
/*!
  \addtogroup View
  \{
*/
/*!
  \brief Provides a %GUI to the user to play the game
  \class GUI View/GUI.h
*/
class GUI : public QMainWindow
{
  Q_OBJECT

public:
  typedef std::unique_ptr<Ui::GUI> UiPtr;
  typedef std::unique_ptr<IController> ControllerPtr;

  explicit GUI(IController* controller);


private slots:

private:
  UiPtr _ui;
  ControllerPtr _controller;
};
/*!\}*/
}
