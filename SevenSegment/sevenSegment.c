#include <lpc22xx.h>
#include <stdint.h>

void initDigit(void) {
	PINSEL0 = 0x00;
	IO0DIR = 0xFF;
}

void displayDigit(uint32_t digit) {
	IO0SET = digit;
}

void clearDigit(void) {
	IO0CLR = 0xFF;
}
