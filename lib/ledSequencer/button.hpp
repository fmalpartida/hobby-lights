#include <inttypes.h>
#include <leds.hpp>
#include <FastIO.h>


#ifndef __BUTTON__
#define __BUTTON__


class button
{
   //
   // Class variables
   fio_register _register;   // IO register
   fio_bit _IObit;           // IO bit
   int _pin;

   typedef void (*buttonCallBack)();

   buttonCallBack clickedEv = NULL;
   buttonCallBack doubleClickedEv = NULL;
   buttonCallBack longClickEv = NULL;

   typedef enum
   {
      NONE = 0,
      CLICK = 1,
      DOUBLE_CLICK = 2,
      LONG_CLICK = 3,

      EVENT_LAST
   } t_buttonEvent;

   // Current state of the button IDLE (initial value)

   uint16_t _pressTimeout;
   uint16_t _clickTimeout;

public:
   typedef enum
   {
      RELEASED = 1,
      PRESSED = 0,

      BUTTON_LAST
   } t_ButtonState;

   // Constructors
   button(int);
   button(int, buttonCallBack click = NULL, buttonCallBack doubleClick = NULL,
      buttonCallBack longClick = NULL);

   // Button current state
   t_ButtonState getState();

   // Button event
   t_buttonEvent getEvent();

};
#endif // __BUTTON__
