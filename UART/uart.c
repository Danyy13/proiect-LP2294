#include<lpc22xx.h>

void uartSet(void) {
	PINSEL0 = 0x5; // set P0.0 -> TX si P0.1 -> RX
	
	// set BAUD rate
	U0LCR = 0x80;
	U0DLL = 0x60;
	
	// enable interrupts
	U0IER = 0x3;
	VICIntEnable = 1u << 6; // UART0 Channel
	VICIntSelect = 1u << 6; // Selectam sa fie FIQ
	
	U0LCR = 0x03;
}

int main(void) {
	
}