#include "xparameters.h"
#include "xgpio.h"
#include "sleep.h"

#define CHANNEL_1 1
#define OUTPUT 0x00

#define  LED_0 0
#define  LED_1 1
#define  LED_2 2
#define  LED_3 3


typedef struct _led{
	int ledNum;
}LedInst;

void Led_init();
void Led_MakeInst(LedInst *led, int ledNum);
void Led_On(LedInst *led);
void Led_Off(LedInst *led);
void Led_Toggle(LedInst *led);
void Led_LeftShift();
void Led_RightShift();
