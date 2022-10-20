#include "xparameters.h"
#include "xgpio.h"
#include "sleep.h"

#define RELEASED 0
#define PUSHED 1

#define OUPUT 0x00
#define INPUT 0x0f

#define CHANNEL_1 1

#define BUTTON_0 0
#define BUTTON_1 1
#define BUTTON_2 2
#define BUTTON_3 3

typedef struct _buttonInst{
	int buttonNum;
	int prevState;
}ButtonInst;

/*서로 다른 부분을 구조체 만들어서 수정해주는게 좋아*/
//(1<<BUTTON_0)
//static int prevState = RELEASED;

void Button_Init();
void Button_MakeInst(ButtonInst* button, int buttonNum);
int Button_GetState(ButtonInst* button);
