#include <button.hpp>
#include <FastIO.h>

// Call periods: 500 us
#define LONG_CLICK_TIMEOUT   1000  // 500ms
#define CLICK_TIMEOUT        300   // 159ms

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

button::button(int pin)
{
   pinMode (pin, INPUT_PULLUP);

   _register = fio_pinToOutputRegister ( pin );
   _IObit = fio_pinToBit(pin);
   _pin = pin;

   _myState = IDLE;

}

button::button (int pin, buttonCallBack click, buttonCallBack doubleClick,
   buttonCallBack longClick)
{
   pinMode (pin, INPUT_PULLUP);
   _pin = pin;
   _register = fio_pinToOutputRegister ( pin );
   _IObit = fio_pinToBit(pin);

   // Setup event callbacks
   clickedEv = click;
   doubleClickedEv = doubleClick;
   longClickEv = longClick;

   // Setup the button initial state
   _myState = IDLE;
}


button::t_ButtonState button::getState()
{
   t_ButtonState state;

   //state = (t_ButtonState)fio_digitalRead(_register, _IObit);
   state = (t_ButtonState)digitalRead(_pin);

   return (state);
}

// method called every TTI
button::t_buttonEvent button::getEvent()
{
   t_ButtonState buttonState = this->getState();
   t_buttonEvent retVal = NONE;
   t_buttonStates currentState = _myState;

   switch( _myState )
   {
      // IDLE state, waiting for button press. On press, arm PRESS timeout
      // for long press.
      case IDLE:

         if (buttonState == PRESSED)
         {
            _myState = PUSHED_1;
            _pressTimeout = LONG_CLICK_TIMEOUT; // Arm the timer for the long press
         }
         break;

      // PUSHED button state: waiting for release every time it goes through
      // it decreases by one the long press timeout on long press transition
      // to long press state and calls pressedEv callback.
      case PUSHED_1:
         _pressTimeout--;

         if (_pressTimeout == 0)
         {
            _myState = LONG_PRESS;
            if (clickedEv != NULL)
            {
               longClickEv();
            }
            retVal = LONG_CLICK;  // PRESSED (LONG PRESS)
         }
         else if ( buttonState == RELEASED )
         {
            _myState = RELEASED_1;
            _clickTimeout = CLICK_TIMEOUT; // Arm the timer for the doble click
         }
         break;

      // RELEASED_1 state: button released, waiting for timeout on released
      // time out, if the button is not pressed again it sends the click event
      // and call the chickedEv callback.
      // If pressed again, moves to double press state.
      case RELEASED_1:
         _clickTimeout--;

         if (_clickTimeout == 0)
         {
            if (clickedEv != NULL)
            {
               clickedEv();
            }
            retVal = CLICK; // SINGLE click
            _myState = IDLE;
         }

         if (buttonState == PRESSED)
         {
            _myState = PUSHED_2;
         }
         break;

      // Double PUSH state: on release it will transition to idle calling
      // the doubleClickedEv and going back to IDLE.
      case PUSHED_2:

         if ( buttonState == RELEASED )
         {
            retVal = DOUBLE_CLICK;  // DOUBLE click

            if ( doubleClickedEv != NULL )
            {
               doubleClickedEv();
            }
            _myState = IDLE;
         }
         break;

      // Long press state: on button release go back to IDLE.
      case LONG_PRESS:
         if ( buttonState == RELEASED )
         {
            _myState = IDLE;
         }

      default:
         break;
      }

      if ( currentState != _myState )
      {
         Serial.print (buttonState);
         Serial.print (", ");
         Serial.println(_myState);
      }
      currentState = _myState;

   return (retVal);
}
