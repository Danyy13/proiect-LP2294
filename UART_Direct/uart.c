#include<lpc22xx.h>

void uartSetup(void) {
	PINSEL0 = 0x5; // set P0.0 -> TX si P0.1 -> RX
	
	// set BAUD rate
	U0LCR = 0x83;
	
	
	// enable interrupts
	//U0IER = 0x3;
	//VICIntEnable = 1u << 6; // UART0 Channel
	//VICIntSelect = 1u << 6; // Selectam sa fie FIQ
	
	U0DLL = 0x78;
	U0DLM = 0x00;
	
	U0LCR = 0x03;
	U0IER = 0x03;
}

void UART0ISR() __irq
{
	//U0LCR = 0x03;
	//char c = 0;
	if(U0LSR & 0x60){
			U0THR = 'a';
	}
	//U0LCR = 0x83;
}

char getchar() {
	char ch = 'z';
	while(!(U0LSR & 0x01)) {}
	ch = U0RBR;
	return ch;
}

void putchar(char ch) {
	while(!(U0LSR & 0x20)) {}
	U0THR = ch;
}

int main(void) {
	char ch = 'a';
	
	uartSetup();
	while(1){
	  ch = getchar();
		 for(int i=0;i<100000;i++) {}
		
		putchar(ch);
	}
}
