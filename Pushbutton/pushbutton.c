#include <lpc22xx.h>
#include <stdint.h>

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

void LED_blink(uint8_t pin) {
	LED_on(pin);
	for (int i = 0;i < 1000000;i++); // delay
	LED_off(pin);
	for (int i = 0;i < 1000000;i++); // delay
}

void Button_init(uint8_t pin) {
	setPinAsGPIO(pin);
	IO0DIR &= ~(1u << pin);
}

int Button_pressed(uint8_t pin) {
	return (IO0PIN & (1u << pin)) == 0; // logca inversa
}

void LED_buttonBlink(uint8_t ledPin, uint8_t buttonPin) {
	if(Button_pressed(buttonPin)) {
		for(int i = 0; i < 1000; i++); // delay
		if(Button_pressed(buttonPin)) {
			LED_on(ledPin);
		} else {
			LED_off(ledPin);
		}
	}
}

#define LEDS 2
#define NR_BUTTON 2

void initArr(uint8_t startPin, uint8_t endPin)
{
	for(uint8_t i = startPin; i <= endPin; i++)
	{
		LED_init(i);
		LED_on(i);
	}
}

int main(void)
{
	uint8_t ledPin = 1;
	 uint8_t buttonPin = 2;
	
	 LED_init(ledPin);
	 Button_init(buttonPin);
	
	//uint8_t startLed = 2, endLed = 3, cursor = 0;
	//uint8_t upButton = 0;
	//uint8_t downButton = 1;
	//initArr(startLed, endLed);
	//Button_init(upButton);
	//Button_init(downButton);
	
	
	// PINSEL0 = PINSEL1 = 0X00000000;
	uint32_t a = IO0SET;
	
	while(1) {
		// LED_blink(ledPin);
		 LED_buttonBlink(ledPin, buttonPin);
		
		//if(Button_pressed(upButton)) {
		//for(int i = 0; i < 1000; i++); // delay
		//	if(Button_pressed(upButton)) {
		//	cursor ++;
		//} 
	//}
	//	LED_off(NR_BUTTON + cursor - 1);
	//	LED_on(NR_BUTTON + cursor);
	/*if(Button_pressed(downButton)) {
		for(int i = 0; i < 1000; i++); // delay
		if(Button_pressed(downButton)) {
			LED_off(NR_BUTTON + cursor --);
			LED_on(NR_BUTTON + cursor);
		} 
	}*/
	
	//cursor %=LEDS;
		
		
		
	}
}
