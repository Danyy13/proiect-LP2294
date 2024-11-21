#include<lpc22xx.h>
#include "timer.h"

#define HALF_SECOND 0x0007A120

void initialiseTimer(void)
{
		T0TCR = 0x2;
		T0TC = 0x0;
    T0PR = 0xF; // 1 us
		T0PC = 0x0;
    
		//T0MR0 = 0xA;
		T0MR0 = HALF_SECOND; // 0.5 s
    
		T0MCR = 0x3; // Interrupt and Reset on MR0
}

void initialiseVector(void) {
	VICIntEnable = 1u << 4; // Timer 0 Channel
	VICIntSelect = 1u << 4; // Selectam sa fie FIQ
}
