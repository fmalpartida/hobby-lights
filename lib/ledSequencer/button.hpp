#include <inttypes.h>
#include <FastIO.h>


#ifndef __BUTTON__
#define __BUTTON__

typedef void (*buttonCallBack)();

class button
{
   // type definition
   // ===============


   typedef enum
   {
      RELEASED = 1,
      PRESSED = 0,

      BUTTON_LAST
   } t_ButtonState;

   // State machine states
   typedef enum
   {
      IDLE       = 0,
      PUSHED_1   = 1,
      RELEASED_1 = 2,
      PUSHED_2   = 3,
      LONG_PRESS = 4,

      BUTTON_STATE_LAST
   } t_buttonStates;

   // Button state machine state
   t_buttonStates _myState;
   //
   // Class variables
   fio_register IOregister;   // IO register
   fio_bit IObit;           // IO bit
   int pin;

   buttonCallBack clickAction = NULL;
   buttonCallBack doubleClickAction = NULL;
   buttonCallBack longClickAction = NULL;

   // Current state of the button IDLE (initial value)

   uint16_t pressTimeout;
   uint16_t clickTimeout;

public:

   typedef enum
   {
      NONE = 0,
      CLICK = 1,
      DOUBLE_CLICK = 2,
      LONG_CLICK = 3,

      EVENT_LAST
   } t_buttonEvent;

   // Constructors
   button(int);
   button(int, buttonCallBack click, buttonCallBack doubleClick,
      buttonCallBack longClick);

   void setClickAction (buttonCallBack);
   void setDoubleClickAction (buttonCallBack);
   void setLongClickAction (buttonCallBack);
   void setActions (buttonCallBack click, buttonCallBack doubleClick,
      buttonCallBack longClick);

   // Button current state
   t_ButtonState getState();

   // Button event
   t_buttonEvent getEvent();

private:
   void setupButton(int);

};
#endif // __BUTTON__
