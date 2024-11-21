#include <stdint.h>

#ifndef SEVEN_SEGMENT_H_
#define SEVEN_SEGMENT_H_

static const uint32_t digitMap[10] = {
	0b11000000,
	0b11111001,
	0b10100100,
	0xB0,
	0b10011001,
	0b10010010,
	0b10000010,
	0xF8,
	0b10000000,
	0b10010000
};

void initDigit(void);
void displayDigit(uint32_t);
void clearDigit(void);

#endif /* SEVEN_SEGMENT_H_ */
