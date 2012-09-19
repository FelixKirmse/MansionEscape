#pragma once
namespace MansionEscape
{
class IModel;

/*!
  \addtogroup Launcher
  \{
*/
/*!
 \brief Struct that controls how the game will be started

 \struct GameOptions GameOptions.h "src/Headers/GameOptions.h"
*/
struct GameOptions
{
  char Interface; /*!< 'g' for GUI, 't' for TUI */
  IModel* Model; /*!< Pointer to the Model that will be used */
  bool CloseApp; /*!< Controls if the app should close */
};
/*!\}*/
}
