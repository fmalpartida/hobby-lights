#include <inttypes.h>
#include <FastIO.h>

#ifndef __LED_SEQUENCE__
#define __LED_SEQUENCE__

class ledSequence
{
   int _pin;
   uint16_t *_sequence;      // LED sequence
   uint16_t _seqLength;      // Sequence length
   uint8_t _bitIndex;        // Bit index
   uint8_t _index;           // Index within vector
   fio_register _register;   // IO register
   fio_bit _IObit;           // IO bit


public:
   ledSequence();
   ledSequence(int);
   ledSequence(int pin, uint16_t *sequence, int length);
   void setLed ( int pin );
   void setSequence (uint16_t *, uint8_t);
   void playNext (void);

};
#endif // __LED_SEQUENCE__
