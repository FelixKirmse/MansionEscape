#include "Controller/Controller.h"
#include "Controller/ContextAction.h"

namespace MansionEscape
{

Controller::Controller(IModel* model)
  : _model(model)
{
}

const UIPackage& Controller::GetUIPackage() const
{
}

void Controller::GoForward()
{
}

void Controller::TurnLeft()
{
}

void Controller::TurnRight()
{
}

void Controller::UseItem(const Item &item)
{
}

void Controller::CommentOnItem(const Item &item)
{
}

void Controller::Inspect()
{
}

void Controller::PerformContextAction(ContextAction action)
{
}

}
