#include "main.h"

int main(void) {
	// 1-. GPIO-en bus-a piztu.
	GPIO_powerOn();
	// 2-. Output/Input-ak ezarriko ditugu.
	GPIO_pinManager(OUT, 2, E);
	GPIO_pinManager(IN, 0, A);
	// 3-. Loop-a hasi.
	while(1) {
		if (GPIO_readPin(0, A)) {
			GPIO_writePin(2, E, ON);
		} else {
			GPIO_writePin(2, E, OFF);
		}
	}
}
