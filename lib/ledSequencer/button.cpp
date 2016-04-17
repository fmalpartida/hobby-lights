#include <button.hpp>
#include <FastIO.h>

// Call periods: 500 us
#define LONG_CLICK_TIMEOUT   100  // 1s
#define CLICK_TIMEOUT        20   // 200ms



button::button(int myPin)
{
   pinMode (myPin, INPUT_PULLUP);

   IOregister = fio_pinToOutputRegister ( pin );
   IObit = fio_pinToBit(pin);
   pin = myPin;

   _myState = IDLE;

}

button::button (int myPin, buttonCallBack click, buttonCallBack doubleClick,
   buttonCallBack longClick)
{
   pinMode (myPin, INPUT_PULLUP);
   pin = myPin;
   IOregister = fio_pinToOutputRegister ( pin );
   IObit = fio_pinToBit(pin);

   // Setup event callbacks
   clickAction = click;
   doubleClickAction = doubleClick;
   longClickAction = longClick;

   // Setup the button initial state
   _myState = IDLE;
}

void button::setClickAction (buttonCallBack action)
{
   clickAction = action;
}

void button::setDoubleClickAction (buttonCallBack action)
{
   doubleClickAction = action;
}

void button::setLongClickAction (buttonCallBack action)
{
   longClickAction = action;
}

void button::setActions (buttonCallBack click, buttonCallBack doubleClick,
   buttonCallBack longClick)
{
   clickAction = click;
   doubleClickAction = doubleClick;
   longClickAction = longClick;
}

button::t_ButtonState button::getState()
{
   t_ButtonState state;

   //state = (t_ButtonState)fio_digitalRead(_register, _IObit);
   state = (t_ButtonState)digitalRead(pin);

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
            pressTimeout = LONG_CLICK_TIMEOUT; // Arm the timer for the long press
         }
         break;

      // PUSHED button state: waiting for release every time it goes through
      // it decreases by one the long press timeout on long press transition
      // to long press state and calls pressedEv callback.
      case PUSHED_1:
         pressTimeout--;

         if (pressTimeout == 0)
         {
            _myState = LONG_PRESS;
            if (longClickAction != NULL)
            {
               longClickAction();
            }
            retVal = LONG_CLICK;  // PRESSED (LONG PRESS)
         }
         else if ( buttonState == RELEASED )
         {
            _myState = RELEASED_1;
            clickTimeout = CLICK_TIMEOUT; // Arm the timer for the doble click
         }
         break;

      // RELEASED_1 state: button released, waiting for timeout on released
      // time out, if the button is not pressed again it sends the click event
      // and call the chickedEv callback.
      // If pressed again, moves to double press state.
      case RELEASED_1:
         clickTimeout--;

         if (clickTimeout == 0)
         {
            if (clickAction != NULL)
            {
               clickAction();
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

            if ( doubleClickAction != NULL )
            {
               doubleClickAction();
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
         Serial.print (pin);
         Serial.print (": ");
         Serial.print (buttonState);
         Serial.print (", ");
         Serial.println(_myState);
      }
      currentState = _myState;

   return (retVal);
}
