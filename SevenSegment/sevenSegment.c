#include <lpc22xx.h>
#include <stdint.h>

void initDigit() {
	PINSEL0 = 0x00;
	IO0DIR = 0xFF;
}

void displayDigit(uint8_t digit) {
	IO0SET = digit;
}

void clearDigit() {
	IO0CLR = 0xFF;
}
