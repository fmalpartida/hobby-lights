#ifndef __SERIAL_MENU__
#define __SERIAL_MENU__

#include <Arduino.h>
#include <program.hpp>

#define SET_PROGRAM   0
#define SET_PERIOD    1
#define LIST_PROGRAMS 2

class command
{
public:
   int8_t myCommand;
   uint16_t value;

   command();
   void execute(program *);
};

class serialMenu
{

public:
   command _command;

   serialMenu();
   command *getCommand();
   void printOptions(program *);
};

#endif // __SERIAL_MENU__
