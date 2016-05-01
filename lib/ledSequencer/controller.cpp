#include <controller.hpp>
#include <inttypes.h>
#include <commonConstants.hpp>

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

extern void upEventFreq ();
extern void downEventFreq ();

controller::controller(uint8_t scanPeriod, button *bUp, button *bDown,
   button *bSelect, program *thisProgram)
   {
      _scanPeriod = scanPeriod;

      up = bUp;
      down = bDown;
      select = bSelect;
      _myProgram = thisProgram;

      _myState = PROGRAM_MODE;
      up->setActions(upEventProgram, upEventProgram, NULL);
      down->setActions(downEventProgram, downEventProgram, NULL);
   }

   void controller::monitorKeyboard()
   {
      button::t_buttonEvent selectEvent;
      static uint8_t counter = _scanPeriod;
      static uint16_t transitionCounter = 100;

      counter--;

      if (counter == 0)
      {
         counter = _scanPeriod;
         // read the buttons and activate their events
         up->getEvent();
         down->getEvent();
         selectEvent = select->getEvent();

         switch (_myState)
         {
            case PROGRAM_MODE:

            // Changing mode to frequency programming mode
            if (selectEvent == button::LONG_CLICK)
            {
               _myProgram->loadProgram(INDICATION_PROGRAM, false);
               _myProgram->setPeriod(INIDICATION_TIMEOUT, false);
               transitionCounter = INIDICATION_TIMEOUT;

               _myState = INDICATION_PRG_FREQ;
#if DEBUT
               Serial.println("TO FREQUENCY");
#endif
            }

            break;

            case INDICATION_PRG_FREQ:

            // If the counter is 0, transition to the frequency programming
            // mode. Load the program that was in memory and reconfigure
            // the actions.
            if (transitionCounter == 0)
            {
               _myState = FREQ_MODE;
               _myProgram->loadProgram(_myProgram->getStoreProgram(), false);
               _myProgram->setPeriod(_myProgram->getStorePeriod(), false);
               up->setActions(upEventFreq, upEventFreq, NULL);
               down->setActions(downEventFreq, downEventFreq, NULL);
            }
            transitionCounter--;

            break;

            case INDICATION_FREQ_PRG:
            // If the counter is 0, transition to the program programming
            // mode. Load the program that was in memory and reconfigure
            // the actions.
            if (transitionCounter == 0)
            {
               _myProgram->loadProgram(_myProgram->getStoreProgram(), false);
               _myProgram->setPeriod(_myProgram->getStorePeriod(), false);
               up->setActions(upEventProgram, upEventProgram, NULL);
               down->setActions(downEventProgram, downEventProgram, NULL);
               _myState = PROGRAM_MODE;
            }
            transitionCounter--;
            break;

            case FREQ_MODE:
            // Changing mode to program programming mode
            if (selectEvent == button::LONG_CLICK)
            {
               _myProgram->loadProgram(INDICATION_PROGRAM, false);
               _myProgram->setPeriod(INIDICATION_TIMEOUT, false);
               transitionCounter = INIDICATION_TIMEOUT;
               _myState = INDICATION_FREQ_PRG;
#if DEBUT
               Serial.println("TO FREQUENCY");
#endif
            }
            break;

            default:
            break;
         }
      }
   }

   void upEventProgram ()
   {
      uint16_t newProgram;

      newProgram = (_myProgram->getCurrentProgram() + 1) %_myProgram->getNumPrograms();
      _myProgram->loadProgram(newProgram, true);
   }

   void downEventProgram()
   {
      uint16_t newProgram = _myProgram->getCurrentProgram();

      if ( newProgram == 0 )
      {
         newProgram = _myProgram->getNumPrograms();
      }
      // Ripple down to one less for all programs
      newProgram--;
      _myProgram->loadProgram(newProgram, true);
   }

   void upEventFreq ()
   {
      uint16_t newFreq;

      newFreq = (_myProgram->getPeriod() + 2) % 512;
      _myProgram->setPeriod(newFreq, true);
   }

   void downEventFreq()
   {
      uint16_t newFreq = _myProgram->getPeriod();

      if (newFreq > 2)
      {
         newFreq -= 2;
      }
      _myProgram->setPeriod(newFreq, true);
   }



   void selectEventProgram()
   {

   }
