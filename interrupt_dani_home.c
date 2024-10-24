#include <lpc22xx.h>
#include <stdint.h>

void LED_init(uint8_t port) {
	PINSEL0 = 0X00000000; // seteaza toti pinii P0.X (X de la 0 la 15) sa fie GPIO
	// PINSEL0 &= ~(3 << 28); // seteaza pinul P0.14 pe GPIO
	IO0DIR |= 1u << port; // setez pinul P0.[port] sa fie output
}

void LED_on(uint8_t port) {
	IO0CLR &= ~(1u << port); // resetez semnalul de LOW de pe pinul port
	IO0SET |= 1u << port; // dau semnal de HIGH pe pinul port
}

void LED_off(uint8_t port) {
	IO0SET = 0x00000000; // might need change - resetez tot registrul IO0SET pentru ca vreau ca pin-ul sa aiba semnal de LOW 
	IO0CLR |= 1u << port; // dau semnal de LOW
}

void Button_init() {
	PINSEL0 &= ~3; // setez pinul P0.0 ca GPIO
	IO0DIR &= ~1u; // setez pinul P0.0 ca input
}

int Button_pressed() {
	return (IO0PIN & 1) == 1;
}

void LED_blink(uint8_t port) {
	LED_on(port);
	for(int i=0;i<10000;i++); // delay
	LED_off(port);
	for(int i=0;i<10000;i++); // delay
}

void LED_buttonBlink(uint8_t port) {
	if(Button_pressed()) {
		for(i = 0; i < 10000; i++); // delay
		if(Button_pressed()) {
			if((IO0PIN >> port) & 1) { // daca LED-ul este deja pornit
				LED_off(port);
			} else {
				LED_on(port);
			}
		}
	}
}

int main(void)
{
	volatile unsigned long int i = 0;
	uint8_t port = 14;
	LED_init(port);
	Button_init();
	
	while(1) {
		LED_blink(port);
		// LED_buttonBlink(port);
	}
	
	return 0;
}
