#include <inttypes.h>
#include <button.hpp>
#include <program.hpp>

#ifndef __CONTROLLER__
#define __CONTROLLER__

class controller
{
   button *up;
   button *down;
   button *select;

public:
   controller(uint8_t scanPeriod, button *bUp, button *bDown, button *bSelect,
      program *thisProgram);

   void monitorKeyboard();
};

#endif // __KEYBOARD_IF__
