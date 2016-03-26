#include <Arduino.h>
#include <ledSequence.hpp>
#include <FastIO.h>

ledSequence::ledSequence()
{
   _bitIndex = 0;
   _index = 0;
}

ledSequence::ledSequence(int pin)
{
   _pin = pin;
   pinMode (_pin, OUTPUT);
   _bitIndex = 0;
   _index = 0;

   _register = fio_pinToOutputRegister ( _pin );
   _IObit = fio_pinToBit(_pin);
}

ledSequence::ledSequence(int pin, uint16_t *sequence, int length)
{
   _pin = pin;
   pinMode (_pin, OUTPUT);
   _bitIndex = 0;
   _index = 0;

   _register = fio_pinToOutputRegister ( _pin );
   _IObit = fio_pinToBit(_pin);

   _sequence = sequence;
   _seqLength = length/sizeof(uint16_t);
}

void ledSequence::setLed ( int pin )
{
   _pin = pin;
   pinMode (_pin, OUTPUT);

   _register = fio_pinToOutputRegister ( _pin );
   _IObit = fio_pinToBit(_pin);
}

void ledSequence::setSequence (uint16_t *sequence, uint8_t length)
{
   _bitIndex = 0;
   _index = 0;

   _sequence = sequence;
   _seqLength = length/sizeof(uint16_t);
}

void ledSequence::playNext ()
{
   //Serial.print((_sequence[_index] >> (15-_bitIndex)) & 1 );
   fio_digitalWrite(_register, _IObit, (_sequence[_index] >> (15-_bitIndex)) & 1 );
   _bitIndex = (_bitIndex + 1) % 16;

   if ( _bitIndex == 0 )
   {
      _index = (_index + 1) % _seqLength;
   }
}
