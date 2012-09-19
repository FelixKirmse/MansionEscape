#pragma once
#include "Controller/IController.h"
#include "Model/IModel.h"
#include <memory>

namespace MansionEscape
{
/*!
  \addtogroup Controller
  \{
*/
/*!
  \brief Controls game state

  \class Controller Controller/Controller
*/
class Controller : public IController
{
public:
  typedef std::unique_ptr<IModel> ModelPtr;

  Controller(IModel* model);

  /* IController Functions Start */
  UIPackage const& GetUIPackage() const;


  void GoForward();
  void TurnLeft();
  void TurnRight();

  void UseItem(Item const& item);
  void CommentOnItem(Item const& item) ;

  void Inspect();
  void PerformContextAction(ContextAction action);
  /* IController Functions End */

private:
  ModelPtr _model;
};
/*!\}*/
}
