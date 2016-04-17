#include <controller.hpp>
#include <inttypes.h>


typedef enum
{
   PROGRAM_MODE,
   INDICATION_PRG_FREQ,
   INDICATION_FREQ_PRG,
   FREQ_MODE,

   CONTROLLER_LAST
} t_controllerStates;

uint8_t _scanPeriod;
t_controllerStates _myState;

program *_myProgram;

extern void upEventProgram();
extern void downEventProgram();
extern void selectEventProgram();

controller::controller(uint8_t scanPeriod, int bUp, int bDown, int bSelect,
   program *thisProgram)
   {
      _scanPeriod = scanPeriod;

      up = new button(bUp);
      down = new button(bDown);
      select = new button(bSelect);
      _myProgram = thisProgram;

      _myState = PROGRAM_MODE;
      up->setActions(upEventProgram, NULL, NULL);
      down->setActions(downEventProgram, NULL, NULL);
   }

   void controller::monitorKeyboard()
   {
      button::t_buttonEvent selectEvent;
      static uint8_t counter = _scanPeriod;

      counter--;

      if (counter == 0)
      {
         counter = _scanPeriod;
         // read the buttons and activate their events
         up->getEvent();
         //down->getEvent();
         //selectEvent = select->getEvent();

         switch (_myState)
         {
            case PROGRAM_MODE:
            break;

            case INDICATION_PRG_FREQ:
            break;

            case INDICATION_FREQ_PRG:
            break;

            case FREQ_MODE:
            break;

            default:
            break;
         }
      }
   }

   void upEventProgram ()
   {
      uint16_t newProgram;

      Serial.println("UP");
      newProgram = (_myProgram->getCurrentProgram() + 1) %_myProgram->getNumPrograms();
      _myProgram->loadProgram(newProgram, true);
   }

   void downEventProgram()
   {

   }

   void selectEventProgram()
   {

   }
