#include "View/GUI.h"
#include "Model/ContextAction.h"
#include "Model/Item.h"
#include <qt4/QtGui/QIcon>
#include <qt4/QtCore/QChar>

namespace MansionEscape
{

GUI::GUI(IController* controller)
  : QMainWindow(0),
    _ui(new Ui::GUI),
    _controller(controller),
    _contextActions(),
    _inventory()
{
  _ui->setupUi(this);
  Update();
}

void GUI::on_Context1Button_pressed()
{
  _controller->PerformContextAction(*_contextActions[0]);
  Update();
}

void GUI::on_Context2Button_pressed()
{
  _controller->PerformContextAction(*_contextActions[1]);
  Update();
}

void GUI::on_Context3Button_pressed()
{
  _controller->PerformContextAction(*_contextActions[2]);
  Update();
}

void GUI::on_CommentItemButton_pressed()
{
  if(_ui->InventoryView->currentItem() == 0)
    _ui->FeedbackArea->setText("Es muss ein Item ausgewählt sein, um es zu kommentieren.");
  QString const& itemName = _ui->InventoryView->currentItem()->text();
  Item const& item = _controller->GetItemByName(itemName.toStdString());
  _ui->FeedbackArea->setText(QString::fromUtf8(item.GetCommentString().c_str()));
}

void GUI::on_InspectButton_pressed()
{
  _ui->FeedbackArea->setText(QString::fromUtf8(_controller->GetRoomInspectString().c_str()));
}

void GUI::on_ForwardButton_pressed()
{
  _controller->GoForward();

  if(_controller->RoomChanged())
    _ui->FeedbackArea->setText(QString::fromUtf8(_controller->GetRoomDescription().c_str()));

  UpdateRoomData();
  UpdateFeedback();
}

void GUI::on_TurnLeftButton_pressed()
{
  _controller->TurnLeft();
  UpdateRoomData();
  UpdateFeedback();
}

void GUI::on_TurnRightButton_pressed()
{
  _controller->TurnRight();
  UpdateRoomData();
  UpdateFeedback();
}

void GUI::Update()
{
  UpdateRoomData();
  UpdateFeedback();
  UpdateItems();
}

void GUI::UpdateRoomData()
{
  _ui->Context1Button->hide();
  _ui->Context2Button->hide();
  _ui->Context3Button->hide();

  _ui->ImageFrame->setPixmap(_controller->GetRoomPicture());
  _contextActions = _controller->GetContextActions();

  size_t actionCount = _contextActions.size();

  if(actionCount == 0)
    return;

  _ui->Context1Button->setText(QString::fromUtf8(_contextActions[0]->GetLabel().c_str()));
  _ui->Context1Button->show();

  if(actionCount == 1)
    return;

  _ui->Context2Button->setText(QString::fromUtf8(_contextActions[1]->GetLabel().c_str()));
  _ui->Context2Button->show();

  if(actionCount == 2)
    return;

  _ui->Context3Button->setText(QString::fromUtf8(_contextActions[2]->GetLabel().c_str()));
  _ui->Context3Button->show();
}

void GUI::UpdateFeedback()
{
  _ui->FeedbackArea->setText(QString::fromUtf8(_controller->GetFeedback().c_str()));
}

void GUI::UpdateItems()
{
  _inventory = _controller->GetInventoryItems();
  _ui->InventoryView->clear();
  for(Item const* item : _inventory)
  {
    new QListWidgetItem(QIcon(item->GetPixMap()),
                        QString::fromUtf8(item->GetName().c_str()),
                        _ui->InventoryView);
  } 
}

}


