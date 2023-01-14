#include "defineMain.h"

#include <iostream>
#include <bitset> //for std::bitset

#if defined(__BIT_MANIPULATION__)
int main() {
	//std::bitset<8> mybitset{}; //8 bits in size means room for 8 flags

	/*
		Given a sequence of bits, we typically number them from right to left start with 0

		76543210 // Bit position
		00000101 // Bit sequence
	*/

	// std::bitset provides four key functions for bit manipulation:
	
	// test() allows us to query whether a bit is 0 or 1
	// set() allows us to turn a bit on (does nothing if the bit is already on)
	// reset() allows us to turn a bit off (does nothing if the bit is already off)
	// flip() allows us to flip a bit value from 0 to 1 or vice versa

	std::bitset<8> bits{ 0b0000'0101 };

	std::cout << "All da bits: " << bits << "\n";

	bits.set(7);

	std::cout << "Bits after setting position 7: " << bits << "\n";

	bits.flip(5);

	std::cout << "Bits after flipping position 5: " << bits << "\n";

	bits.reset(0);

	std::cout << "Bits after resetting position 0: " << bits << "\n";


	return 0;
}

#endif