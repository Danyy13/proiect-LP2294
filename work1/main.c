#include <lpc22xx.h>
#include <stdint.h>

void setPinAsGPIO(uint8_t pin) {
	if (pin & 0xF0) { // verificare daca pin >= 16
		PINSEL1 &= ~(0b11 << ((pin - 16) / 2));
		//PINSEL1 = 0x00000000; // seteaza toti pinii P0.X (X de la 16 la 31) sa fie GPIO
	}
	else {
		PINSEL0 = ~(0b11 << (pin / 2));
		//PINSEL0 = 0X00000000; // seteaza toti pinii P0.X (X de la 0 la 15) sa fie GPIO
	}
}

void LED_init(uint8_t pin) {
	setPinAsGPIO(pin); // seteaza pinul sa aiba functie de GPIO
	IO0DIR |= 1u << pin; // setez pinul P0.[pin] sa fie output
}

void LED_on(uint8_t pin) {
	IO0SET |= 1u << pin; // dau semnal de HIGH pe pinul pin
}

void LED_off(uint8_t pin) {
	IO0CLR |= 1u << pin; // dau semnal de LOW
}

void LED_blink(uint8_t pin) {
	LED_on(pin);
	for (int i = 0;i < 1000000;i++); // delay
	LED_off(pin);
	for (int i = 0;i < 1000000;i++); // delay
}

//void Button_init(uint8_t pin) {
//	setPinAsGPIO(pin);
//	IO0DIR &= ~(1u << pin); // setez pinul P0.0 ca input
//}
//
//int Button_pressed(uint8_t pin) {
//	return (IO0PIN & (1u << pin)) == 0; // logca inversa
//}
//
//void LED_buttonBlink(uint8_t ledPin, uint8_t buttonPin) {
//	if(Button_pressed(buttonPin)) {
//		for(i = 0; i < 10000; i++); // delay
//		if(Button_pressed(buttonPin)) {
//				LED_on(ledPin);
//			} else {
//				LED_off(ledPin);
//			}
//		}
//	}
//}

int main(void)
{
	uint8_t ledPin = 14;
	//uint8_t buttonPin = 1;
	
	LED_init(ledPin);
	//Button_init(buttonPin);
	
	while(1) {
		LED_blink(ledPin);
		// LED_buttonBlink(pin);
	}
	
	return 0;
}
