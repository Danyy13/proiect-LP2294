#include<lpc22xx.h>
#include<stdint.h>
#include "timer.h"

#define PIN 5

uint8_t isLedOn;

uint8_t flag = 0;


void myirq(void) __irq
{
	T0IR |= 1;
}


void setPinAsGPIO(uint8_t pin) {
	if (pin & 0xF0) { // verificare daca pin >= 16
		//PINSEL1 &= ~(0b11 << ((pin - 16) * 2));
		PINSEL1 = 0x00000000; // seteaza toti pinii P0.X (X de la 16 la 31) sa fie GPIO
	} else {
		//PINSEL0 &= ~(0b11 << (pin * 2));
		PINSEL0 = 0X00000000; // seteaza toti pinii P0.X (X de la 0 la 15) sa fie GPIO
	}
}

void LED_init(uint8_t pin) {
	setPinAsGPIO(pin); // seteaza pinul sa aiba functie de GPIO
	IO0DIR |= (1u << pin); // setez pinul P0.[pin] sa fie output
}

void LED_on(uint8_t pin) {
	IO0SET |= (1u << pin); // dau semnal de HIGH pe pinul pin
}

void LED_off(uint8_t pin) {
	IO0CLR |= (1u << pin); // dau semnal de LOW
}


void Timer0ISR() __irq
{

	
		// blink LED
	
		if(isLedOn) {
			LED_off(PIN);
			isLedOn = 0;
		} else {
			LED_on(PIN);
			isLedOn = 1;
		}
			T0IR = 0x01;
}


int main(void)
{
		initialiseTimer();
	  initialiseVector();
	
		uint8_t led = PIN;
		isLedOn = 0;
	
		LED_init(led);
		// LED_on(led);

		T0TCR = 0x1;
    while(1) {
			//if(flag) {
			//	LED_off(led);
			//} else {
			//	LED_on(led);
			//}
    }
}
