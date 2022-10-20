#include "button.h"

XGpio GPIO_BTN;

void Button_Init()
{
	XGpio_Initialize(&GPIO_BTN, XPAR_AXI_GPIO_1_DEVICE_ID);
	XGpio_SetDataDirection(&GPIO_BTN, CHANNEL_1, 0xff);
}

void Button_MakeInst(ButtonInst* button, int buttonNum)
{
	button->prevState = RELEASED;
	button->buttonNum = buttonNum;
}

int Button_GetState(ButtonInst* button)
{
//	static int prevState = RELEASED;

	int curState = XGpio_DiscreteRead(&GPIO_BTN, CHANNEL_1) & (1<<button->buttonNum);

	if(curState != RELEASED && button->prevState == RELEASED){
		usleep(20000);
		button->prevState = PUSHED;
		return FALSE;
	}
	else if(curState == RELEASED && button->prevState != RELEASED){
		usleep(20000);				//debouncing
		button->prevState = RELEASED;
		return TRUE;
	}
	return FALSE;
}
