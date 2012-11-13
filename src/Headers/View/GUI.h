#pragma once
#include <qt4/QtGui/QMainWindow>
#include <qt4/QtGui/QListWidgetItem>
#include <memory>
#include "View/ui_GUI.h"
#include "Controller/IController.h"
#include <vector>

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
  void on_Context1Button_pressed();
  void on_Context2Button_pressed();
  void on_Context3Button_pressed();
  void on_CommentItemButton_pressed();
  void on_InspectButton_pressed();
  void on_ForwardButton_pressed();
  void on_TurnLeftButton_pressed();
  void on_TurnRightButton_pressed();

private:
  void UpdateRoomData();
  void UpdateFeedback();
  void UpdateItems();

  UiPtr _ui;
  ControllerPtr _controller;

  IController::ActionVec _contextActions;
  IController::ItemVec _inventory;
};
/*!\}*/
}
