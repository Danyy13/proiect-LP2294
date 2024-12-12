#include<lpc22xx.h>

void uartSetup(void) {
	PINSEL0 = 0x5; // set P0.0 -> TX si P0.1 -> RX
	
	// set BAUD rate
	U0LCR = 0x83;
	
	
	// enable interrupts
	U0IER = 0x3;
	VICIntEnable = 1u << 6; // UART0 Channel
	VICIntSelect = 1u << 6; // Selectam sa fie FIQ
	
	U0FCR = 0x01;
	
	U0DLL = 0x78;
	U0DLM = 0x00;
	
	U0LCR = 0x03;
	U0IER = 1;
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
volatile unsigned int n = 0;
void UART0ISR() __irq
{
	
	if ((U0IIR & 1) == 0)
	{
		n = 1;
		
	}
	
	VICVectAddr = 0;
	//putchar(c);
}

int main(void) {
	//char ch = 'a';
	
	uartSetup();
	while(1)
	{
		if (n == 1)
		{
			putchar('a');
			n = 0;
		}
	}
		/*{
	  ch = getchar();
		 for(int i=0;i<100000;i++) {}
		
		putchar(ch);
	}*/
}
