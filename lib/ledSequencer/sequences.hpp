#include <inttypes.h>

#ifndef __SEQUENCE__
#define __SEQUENCE__

// Predefined sequences
// ====================

uint16_t fixed[] = { 0b1111111111111111 };

// Blinks
// -----------------------------------------------------------------------------
// Double blink
uint16_t doubleBlink0[] = { 0b1111111100000000, 0b1111111100000000, 0b0000000000000000, 0b0000000000000000};
uint16_t doubleBlink90[] = { 0b0000000011111111, 0b0000000011111111, 0b0000000000000000, 0b0000000000000000};
uint16_t doubleBlink180[] = { 0b0000000000000000, 0b1111111100000000, 0b1111111100000000, 0b0000000000000000};
uint16_t doubleBlink270[] = { 0b0000000000000000, 0b0000000011111111, 0b0000000011111111, 0b0000000000000000};

// Long blinks
uint16_t blink0[]   = { 0b1111111111111111, 0b0000000000000000 }; // 0 shift
uint16_t blink90[]  = { 0b0000000011111111, 0b1111111100000000 }; // 90 shift
uint16_t blink180[] = { 0b0000000000000000, 0b1111111111111111 };   // 180 shift
uint16_t blink270[] = { 0b1111111100000000, 0b0000000011111111 };   // 270 shift

// Long blinks
uint16_t blinkP0[]   = { 0b1111111111111111, 0b0000000000000000, 0b0000000000000000, 0b0000000000000000 }; // 0 shift
uint16_t blinkP90[]  = { 0b0000000011111111, 0b1111111100000000, 0b0000000000000000, 0b0000000000000000 }; // 90 shift
uint16_t blinkP180[] = { 0b0000000000000000, 0b1111111111111111, 0b0000000000000000, 0b0000000000000000 };   // 180 shift
uint16_t blinkP270[] = { 0b0000000000000000, 0b0000000011111111, 0b1111111100000000, 0b0000000000000000 };   // 270 shift
uint16_t blinkP0b[]   = { 0b0000000000000000, 0b0000000000000000, 0b1111111111111111, 0b0000000000000000 }; // 0 shift
uint16_t blinkP90b[]  = { 0b0000000000000000, 0b0000000000000000, 0b0000000011111111, 0b1111111100000000 }; // 90 shift
uint16_t blinkP180b[] = { 0b0000000000000000, 0b0000000000000000, 0b0000000000000000, 0b1111111111111111 };   // 180 shift
uint16_t blinkP270b[] = { 0b1111111100000000, 0b0000000000000000, 0b0000000000000000, 0b0000000011111111 };   // 270 shift


// Fast blink
uint16_t fastBlink0[]     = { 0b1111111100000000 };  // 0 shift
uint16_t fastBlink90[]    = { 0b0000111111110000 }; // 90 shift
uint16_t fastBlink180[]   = { 0b0000000011111111 }; // 180 shift
uint16_t fastBlink270[]   = { 0b1111000000001111 }; // 180 shift

// Very fast blink
uint16_t veryFastBlink0[] = { 0b0101010101010101 };
uint16_t veryFastBlink180[] = { 0b1010101010101010 };

// Bursts
// -----------------------------------------------------------------------------
uint16_t fastBlinkP0[]   = { 0b0101010101010101, 0b0000000000000000 };
uint16_t fastBlinkP90[]  = { 0b0000001011010101, 0b0101000000000000 };
uint16_t fastBlinkP180[] = { 0b0000000001010101, 0b0101010100000000 };
uint16_t fastBlinkP270[] = { 0b0000000000000000, 0b0101010101010101 };

uint16_t fastBlinkLP0[]   = { 0b0101010101010101, 0b0000000000000000, 0b0000000000000000 };
uint16_t fastBlinkLP90[]  = { 0b0000000001010101, 0b0101010100000000, 0b0000000000000000 };
uint16_t fastBlinkLP180[] = { 0b0000000000000000, 0b0101010101010101, 0b0000000000000000 };
uint16_t fastBlinkLP270[] = { 0b0000000000000000, 0b0000000001010101, 0b0101010100000000 };

// Random flicker
// -----------------------------------------------------------------------------
uint16_t randFliker0[]   = { 0b0100010111010111, 0b0010011100101010 };
uint16_t randFliker180[] = { 0b0010011100101010, 0b0100010111010111  };

uint16_t randFlikerP0[]   = { 0b0100010111010111, 0b0010011100101010, 0b0000000000000000 };
uint16_t randFlikerP180[] = { 0b0010011100101010, 0b0100010111010111,  0b0000000000000000 };

uint16_t randFlikerLP0[]   = { 0b0100010111010111, 0b0010011100101010, 0b0000000000000000, 0b0000000000000000 };
uint16_t randFlikerLP180[] = { 0b0010011100101010, 0b0100010111010111,  0b0000000000000000, 0b0000000000000000 };

// Bursts
uint16_t burst0[]  = {0b0100010111010111, 0b0000000000000000};
uint16_t burst1[]  = {0b1011101000101000, 0b0000000000000000};
uint16_t burst0_90[]  = {0b0000000000000000, 0b0100010111010111};
uint16_t burst1_90[]  = {0b0000000000000000, 0b1011101000101000};
uint16_t burstLP0[]  = {0b0100010111010111, 0b0000000000000000, 0b0000000000000000};
uint16_t burstLP1[]  = {0b1011101000101000, 0b0000000000000000, 0b0000000000000000};
uint16_t burstLP0_90[]  = {0b0000000000000000, 0b0100010111010111, 0b0000000000000000};
uint16_t burstLP1_90[]  = {0b0000000000000000, 0b1011101000101000, 0b0000000000000000};



typedef struct
{
   uint16_t *sequence;
   uint8_t seqSize;
   char name[];
} t_sequence;

#define FIXED               0
#define DOUBLE_BLINK_0      1
#define DOUBLE_BLINK_90     2
#define DOUBLE_BLINK_180    3
#define DOUBLE_BLINK_270    4
#define BLINK_0             5
#define BLINK_90            6
#define BLINK_180           7
#define BLINK_270           8
#define FAST_BLINK_0        9
#define FAST_BLINK_90       10
#define FAST_BLINK_180      11
#define FAST_BLINK_270      12
#define VFAST_BLINK_0       13
#define VFAST_BLINK_180     14
#define FAST_BLINK_P_0      15
#define FAST_BLINK_P_90     16
#define FAST_BLINK_P_180    17
#define FAST_BLINK_P_270    18
#define FAST_BLINK_LP_0     19
#define FAST_BLINK_LP_90    20
#define FAST_BLINK_LP_180   21
#define FAST_BLINK_LP_270   22
#define RAND_FLICK_0        23
#define RAND_FLICK_180      24
#define RAND_FLICK_P_0      25
#define RAND_FLICK_P_180    26
#define RAND_FLICK_LP_0     27
#define RAND_FLICK_LP_180   28
#define BURST_0             29
#define BURST_1             30
#define BURST_0_90          31
#define BURST_1_90          32
#define BURSTLP_0           33
#define BURSTLP_1           34
#define BURSTLP_0_90        35
#define BURSTLP_1_90        36
#define BLINKP_0            37
#define BLINKP_90           38
#define BLINKP_180          39
#define BLINKP_270          40
#define BLINKP_0B           41
#define BLINKP_90B          42
#define BLINKP_180B         43
#define BLINKP_270B         44

#define SET_SEQUENCE(seq) seq, sizeof(seq)

t_sequence sequenceList[] =
{
   {SET_SEQUENCE(fixed)}, // 0

   {SET_SEQUENCE(doubleBlink0)},   // 1
   {SET_SEQUENCE(doubleBlink90)},  // 2
   {SET_SEQUENCE(doubleBlink180)}, // 3
   {SET_SEQUENCE(doubleBlink270)}, // 4

   {SET_SEQUENCE(blink0)},    // 5
   {SET_SEQUENCE(blink90)},   // 6
   {SET_SEQUENCE(blink180)},  // 7
   {SET_SEQUENCE(blink270)},  // 8

   {SET_SEQUENCE(fastBlink0)},    // 9
   {SET_SEQUENCE(fastBlink90)},   // 10
   {SET_SEQUENCE(fastBlink180)},  // 11
   {SET_SEQUENCE(fastBlink270)},  // 12

   {SET_SEQUENCE(veryFastBlink0)},   // 13
   {SET_SEQUENCE(veryFastBlink180)}, // 14

   {SET_SEQUENCE(fastBlinkP0)},   // 15
   {SET_SEQUENCE(fastBlinkP90)},  // 16
   {SET_SEQUENCE(fastBlinkP180)}, // 17
   {SET_SEQUENCE(fastBlinkP270)}, // 18

   {SET_SEQUENCE(fastBlinkLP0)},   // 19
   {SET_SEQUENCE(fastBlinkLP90)},  // 20
   {SET_SEQUENCE(fastBlinkLP180)}, // 21
   {SET_SEQUENCE(fastBlinkLP270)}, // 22

   {SET_SEQUENCE(randFliker0)},   // 23
   {SET_SEQUENCE(randFliker180)}, // 24

   {SET_SEQUENCE(randFlikerP0)},   // 25
   {SET_SEQUENCE(randFlikerP180)}, // 26

   {SET_SEQUENCE(randFlikerLP0)},  // 27
   {SET_SEQUENCE(randFlikerLP180)},// 28

   {SET_SEQUENCE(burst0)}, // 29
   {SET_SEQUENCE(burst1)}, // 30
   {SET_SEQUENCE(burst0_90)}, // 31
   {SET_SEQUENCE(burst1_90)}, // 32

   {SET_SEQUENCE(burstLP0)}, // 33
   {SET_SEQUENCE(burstLP1)}, // 34
   {SET_SEQUENCE(burstLP0_90)}, // 35
   {SET_SEQUENCE(burstLP1_90)}, // 36

   {SET_SEQUENCE(blinkP0)},    // 37
   {SET_SEQUENCE(blinkP90)},   // 38
   {SET_SEQUENCE(blinkP180)},  // 39
   {SET_SEQUENCE(blinkP270)},   // 40
   {SET_SEQUENCE(blinkP0b)},    // 41
   {SET_SEQUENCE(blinkP90b)},   // 42
   {SET_SEQUENCE(blinkP180b)},  // 43
   {SET_SEQUENCE(blinkP270b)},   // 44

};


#endif // __SEQUENCES__
