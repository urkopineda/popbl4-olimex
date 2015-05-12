#ifndef _API

#include <stdint.h>
#include <stm32f4xx.h>

#define A 0
#define E 1
#define IN 0
#define OUT 1
#define OFF 0
#define ON 1

// 1.a-. Switch power of GPIO x.
void GPIO_powerSwitch(int gpio);
// 1.b-. Set input/output pin mode. MODE -> IN = 1; OUT = 0; | PIN -> 0 - 15.
void GPIO_pinManager(int mode, int pin, int gpio);
// 1.c-. Switch on/off output pins. MODE -> ON = 1; OFF = 0; | PIN -> 0 - 15.
void GPIO_powerSwitchPin(int mode, int pin, int gpio);
// 1.d-. Read. 
int GPIO_readPin(int pin, int gpio);
// 1.e-. Write.
void GPIO_writePin(int pin, int gpio, int mode);
// 1.f-. Switch GPIO F and G On.
void GPIO_powerOn(void);

#endif
