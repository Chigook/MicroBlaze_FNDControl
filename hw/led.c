#include "led.h"

XGpio GPIO_LED;

void Led_init()
{
	XGpio_Initialize(&GPIO_LED, XPAR_AXI_GPIO_0_DEVICE_ID);			// GPIO init
	XGpio_SetDataDirection(&GPIO_LED, CHANNEL_1, OUTPUT);
}

void Led_MakeInst(LedInst *led, int ledNum)
{
	led->ledNum = ledNum;
}

void Led_On(LedInst *led)
{
	int ledState = XGpio_DiscreteRead(&GPIO_LED, CHANNEL_1);
	XGpio_DiscreteWrite(&GPIO_LED, CHANNEL_1, ledState | (1<<led->ledNum));
}

void Led_Off(LedInst *led)
{
	int ledState = XGpio_DiscreteRead(&GPIO_LED, CHANNEL_1);
	XGpio_DiscreteWrite(&GPIO_LED, CHANNEL_1, ledState & ~(1<<led->ledNum));
}

void Led_Toggle(LedInst *led)
{
	int ledState = XGpio_DiscreteRead(&GPIO_LED, CHANNEL_1);
	XGpio_DiscreteWrite(&GPIO_LED, CHANNEL_1, (ledState ^ (1<<led->ledNum)));
}

void Led_LeftShift()
{
	for(int i=0; i<8; i++){
		XGpio_DiscreteWrite(&GPIO_LED, CHANNEL_1, 1<<i);
		usleep(300000);
	}
}

void Led_RightShift()
{
	for(int i=8; i>0; i--){
		XGpio_DiscreteWrite(&GPIO_LED, CHANNEL_1, 1<<(i-1));
		usleep(300000);
	}
}


