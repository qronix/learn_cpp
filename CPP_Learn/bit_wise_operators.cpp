#include "defineMain.h"

#include <iostream>
#include <bitset>

#if defined(__BIT_WISE_OPERATORS__)

// bitwise rotate left
std::bitset<4> rotl(std::bitset<4> bits) {
	const bool isRotatedBitSet{ bits.test(3) };

	bits <<= 1;

	return (isRotatedBitSet ? bits.set(0) : bits);
}


int main() {

	std::bitset<4> bits{ 0b0000 };

	std::cout << "Initial bits: " << bits << "\n";

	// set bits in position 3 and 1
	bits.set(3);
	bits.set(1);

	std::cout << "Bits in position 3 and 1 set: " << bits << "\n";

	// Bitwise left shift << operator
	std::cout << "Bits shifted left by one: " << (bits << 1) << "\n";

	// Bitwise right shift >> operator
	std::cout << "Bits shifted right by two: " << (bits >> 2) << "\n";

	// Bitwise NOT operator (flips bits)
	std::cout << "Bits with NOT operator: " << (~bits) << "\n";

	// Note, Bitwise NOT is dependent upon size of data type
	std::cout << "Using ~ NOT on a bitset of size 8 with value of 0b0100:\n";
	std::cout << ~std::bitset<8>{0b0100} << "\n";

	// Bitwise OR |
	std::cout << "Bitwise OR | of 0b1010 and 0b0001: \n";
	std::cout << (std::bitset<4>{0b1010} | std::bitset<4>{0b0001}) << "\n";

	// Bitwise AND &
	std::cout << "Bitwise AND & of 0b1011 and 0b0101: \n";
	std::cout << (std::bitset<4>{0b1011} & std::bitset<4>{0b0101}) << "\n";

	// Bitwise XOR ^
	std::cout << "Bitwise XOR ^ of 0b0110 and 0b1110: \n";
	std::cout << (std::bitset<4>{0b0110}^ std::bitset<4>{0b1110}) << "\n";

	/*
		Bitwise assignment operators are also a thing:
		
		Left shift assignment:   <<=		x <<= y

		Right shift assignment:  >>=		x >>= y

		OR assignment:			 |=			x |= y

		AND assignment:			 &=			x &= y

		XOR assignment:			 ^=			x ^= y

	*/


	/*
		Summary of bitwise operators:

		Summarizing how to evaluate bitwise operations utilizing the column method:

		 - When evaluating bitwise OR, if any bit in a column is 1, the result for that column is 1.
		 - When evaluating bitwise AND, if all bits in a column are 1, the result for that column is 1.
		 - When evaluating bitwise XOR, if there are an odd number of 1 bits in a column, the result for that column is 1.
		
	*/

	std::cout << "Rotating 0b1001u left: \n";
	std::cout << rotl(std::bitset<4>{0b1001u}) << "\n";
	
	std::cout << "Rotating 0b1000u left: \n";
	std::cout << rotl(std::bitset<4>{0b1000u}) << "\n";

	return 0;
}

#endif