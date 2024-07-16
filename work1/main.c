#include <lpc22xx.h>

void LED_init() {
	PINSEL1 &= ~(3 << 28); // setez pinul P30 sa fie GPIO
	IO0DIR |= 1u << 30; // setez P30 sa fie output
}

void LED_on() {
	IO0SET = 1 << 30; // dau semnal de HIGH
}

void LED_off() {
	IO0CLR = 1 << 30; // dau semnal de LOW
}

void Button_init() {
	PINSEL0 &= ~3; // 14
	IO0DIR &= ~1u; // set as input
}

int Button_pressed() {
	return (IO0PIN & 1) == 1;
}

int main(void)
{
	volatile unsigned long int i = 0;
	LED_init();
	Button_init();
	
	while(1) {
		if(Button_pressed()) {
			for(i = 0; i < 1000; i++);
			if(Button_pressed()) {
				LED_on();
			}
		}
	}
	
	return 0;
}
