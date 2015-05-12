#include "gpio_api.h"

// 1.a-. Switch power of GPIO x (Page 238)
void GPIO_powerSwitch(int gpio) {
	if (gpio == A) {
		RCC->AHB1ENR ^= 1;
	} else if (gpio == E) {
		RCC->AHB1ENR ^= (1 << 4);
	}
}

// 1.b-. Set input/output pin mode. MODE -> IN = 1; OUT = 0; | PIN -> 0 - 15 (Page 278)
void GPIO_pinManager(int mode, int pin, int gpio) {
	if (!((pin >= 0) && (pin < 16))) return;
	if (!((mode == IN) || (mode == OUT))) return;
	if (gpio == A) {
		GPIOA->MODER &= ~(3 << (pin * 2)); // 00
		if (mode == OUT) {
			GPIOA->MODER |= (1 << (pin * 2)); // 01
		}
	} else if (gpio == E) {
		GPIOE->MODER &= ~(3 << (pin * 2)); // 00
		if (mode == OUT) {
			GPIOE->MODER |= (1 << (pin * 2)); // 01
		}
	}
}

// 1.c-. Switch on/off output pins. MODE -> ON = 1; OFF = 0; | PIN -> 0 - 15 (Page 281)
void GPIO_powerSwitchPin(int mode, int pin, int gpio) {
	if (!((pin >= 0) && (pin < 16))) return;
	if (!((mode == ON) || (mode == OFF))) return;
	pin += (16 * (1 - mode));
	if (gpio == A) {
		GPIOA->BSRRH |= (1 << pin);
	} else if (gpio == E) {
		GPIOE->BSRRH |= (1 << pin);	
	}
}

// 1.d-. Read (Page 280)
int GPIO_readPin(int pin, int gpio) {
	if ((pin >= 0) && (pin < 16)) {
		if (gpio == A) {
			return (int) (GPIOA->IDR & (1 << pin));
		} else if (gpio == E) {
			return (int) (GPIOE->IDR & (1 << pin));
		}
	} else {
		return -1;
	}
	return 0;
}

// 1.e-. Write (Page 281)
void GPIO_writePin(int pin, int gpio, int mode) {
	if ((pin >= 0) && (pin < 16)) {
		if (gpio == A) {
			if (mode == ON) { 
				GPIOA->ODR |= (1 << pin);
			} else if (mode == OFF) {
				GPIOA->ODR &= ~(1 << pin);
			}
		} else if (gpio == E) {
			if (mode == ON) {
				GPIOE->ODR |= (1 << pin);
			} else if (mode == OFF) {
				GPIOE->ODR &= ~(1 << pin);
			}
		}
	}
}

// 1.f-. Switch GPIO F and G On.
void GPIO_powerOn(void) {
	GPIO_powerSwitch(A);
	GPIO_powerSwitch(E);
}
