#include<lpc22xx.h>

#define HALF_SECOND 0x0007A120

void Initialise(void)
{
		T0TCR = 0x0;
    T0PR = 0xF; // 1 us
    T0MR0 = HALF_SECOND; // 0.5 s
    T0MCR = 0x3; // Interrupt and Reset on MR0
		T0TC = 0x0;
		T0PC = 0x0;
}
void Timer0ISR(void) __irq;


int main(void)
{


		T0TCR = 0x1;
    while(1)
    {

    }
}