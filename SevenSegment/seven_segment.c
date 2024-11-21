#include <lpc22xx.h>
#include "sevenSegment.h"
#include "timer.h"

// TODO rutina de interrupt

int main() {
	// initialiseTimer();
	// initialiseVector();
	
	initDigit();
	
	while(1) {
		// seven segment
		for(int i=0;i<10;i++) {
			// display digit
			displayDigit(digitMap[i]);
			for(int j=0;j<1000000;j++) {}
			clearDigit();
		}
		
		// UART
		
		// set BAUD rate
		// P0.0 = TXD0
		// P0.1 = RXD0
	}
}


