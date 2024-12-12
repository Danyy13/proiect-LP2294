#inlcude <lpc22xx.h>

void adcInit() {
	PINSEL1 = 3 << 22; // set pin as Analog
	
	ADCR = 1 | (1 << 21) | (1 << 24);
}

int main(void) {
	
	while(1) {
		
	}
}