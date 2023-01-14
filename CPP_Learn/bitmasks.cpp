// https://www.learncpp.com/cpp-tutorial/bit-manipulation-with-bitwise-operators-and-bit-masks/

#include "defineMain.h"

#include <iostream>
#include <bitset>
#include <cstdint>

#if defined(__BIT_MASKS__)
int main() {

	// Bit masks for 8 bits

	// A zero-value in a bitmask "masks" that position in the bit field
	// A value of one, indicates a value we want to change
	constexpr std::uint8_t mask0{ 0b0000'0001 }; // represents bit position 0
	constexpr std::uint8_t mask1{ 0b0000'0010 }; // represents bit position 1
	constexpr std::uint8_t mask2{ 0b0000'0100 }; // represents bit position 2
	//constexpr std::uint8_t mask3{ 0b0000'1000 }; // represents bit position 3
	constexpr std::uint8_t mask4{ 0b0001'0000 }; // represents bit position 4
	constexpr std::uint8_t mask5{ 0b0010'0000 }; // represents bit position 5
	constexpr std::uint8_t mask6{ 0b0100'0000 }; // represents bit position 6
	constexpr std::uint8_t mask7{ 0b1000'0000 }; // represents bit position 7


	std::uint8_t flags{ 0b0000'0101 }; // 8 bits in size, means room for 8 flags

	// Determine if a bit is on by using the bitwise AND operator with the flags
	// and the bitmask
	std::cout << "bit 0 is " << ((flags & mask0) ? "on\n" : "off\n");
	std::cout << "bit 1 is " << ((flags & mask1) ? "on\n" : "off\n");
	
	// turn on bit 1 via the bitwise OR operator
	flags |= mask1;

	std::cout << "bit 1 after using bitwise OR assignment is: " << ((flags & mask1) ? "on\n" : "off\n");


	// turn on multiple bits at the same time via bitwise OR:
	flags |= (mask4 | mask5);

	std::cout << "Flags after turning on bits 4 and 5 at the same time: " << static_cast<std::bitset<8>>(flags) << "\n";

	// clear a bit (turn off), using bitwise AND and NOT together
	flags &= ~mask2;

	std::cout << "bit 2 after using bitwise AND and NOT to clear bit is: " << ((flags & mask2) ? "on\n" : "off\n");

	
	// clear multiple bits at the same time using bitwise AND, NOT, and OR

	flags &= ~(mask4 | mask5);

	std::cout << "Flags after clearing bits 4 and 5 at the same time: " << static_cast<std::bitset<8>>(flags) << "\n";


	// Bits can be flipped via bitwise XOR

	flags ^= mask6;
	std::cout << "bit 6 was flipped via XOR and is: " << ((flags & mask6) ? "on\n" : "off\n");

	std::cout << "Flags is now: " << static_cast<std::bitset<8>>(flags) << "\n";

	// Multiple bits can be flipped at the same time using XOR and OR

	flags ^= (mask6 | mask7);
	std::cout << "Flags after flipping bits 6 and 7: " << static_cast<std::bitset<8>>(flags) << "\n";

	/*
		Bitmasks should have meaningful names (not mask1, mask2, ....)
	
			// Define a bunch of physical/emotional states
			constexpr std::uint8_t isHungry{	1 << 0 }; // 0000 0001
			constexpr std::uint8_t isSad{		1 << 1 }; // 0000 0010
			constexpr std::uint8_t isMad{		1 << 2 }; // 0000 0100
			constexpr std::uint8_t isHappy{		1 << 3 }; // 0000 1000
			constexpr std::uint8_t isLaughing{ 	1 << 4 }; // 0001 0000
			constexpr std::uint8_t isAsleep{	1 << 5 }; // 0010 0000
			constexpr std::uint8_t isDead{		1 << 6 }; // 0100 0000
			constexpr std::uint8_t isCrying{	1 << 7 }; // 1000 0000

			std::uint8_t me{}; // all flags/options turned off to start
			me |= (isHappy | isLaughing); // I am happy and laughing
			me &= ~isLaughing; // I am no longer laughing

			// Query a few states
			// (we'll use static_cast<bool> to interpret the results as a boolean value)
			std::cout << "I am happy? " << static_cast<bool>(me & isHappy) << '\n';
			std::cout << "I am laughing? " << static_cast<bool>(me & isLaughing) << '\n';


			// ================= And the same example using std::bitset ===================================

			// Define a bunch of physical/emotional states
			constexpr std::bitset<8> isHungry{	0b0000'0001 };
			constexpr std::bitset<8> isSad{		0b0000'0010 };
			constexpr std::bitset<8> isMad{		0b0000'0100 };
			constexpr std::bitset<8> isHappy{	0b0000'1000 };
			constexpr std::bitset<8> isLaughing{	0b0001'0000 };
			constexpr std::bitset<8> isAsleep{	0b0010'0000 };
			constexpr std::bitset<8> isDead{	0b0100'0000 };
			constexpr std::bitset<8> isCrying{	0b1000'0000 };


			std::bitset<8> me{}; // all flags/options turned off to start
			me |= (isHappy | isLaughing); // I am happy and laughing
			me &= ~isLaughing; // I am no longer laughing

			// Query a few states (we use the any() function to see if any bits remain set)
			std::cout << "I am happy? " << (me & isHappy).any() << '\n';
			std::cout << "I am laughing? " << (me & isLaughing).any() << '\n';


	*/

	// Because binary literals are not implemented in C++11 or earlier
	// there exists two ways to handle bit masks for these versions of C++


	// This method uses hexadecimal representations of the bit mask
	/*
		constexpr std::uint8_t mask0{ 0x01 }; // hex for 0000 0001
		constexpr std::uint8_t mask1{ 0x02 }; // hex for 0000 0010
		constexpr std::uint8_t mask2{ 0x04 }; // hex for 0000 0100
		constexpr std::uint8_t mask3{ 0x08 }; // hex for 0000 1000
		constexpr std::uint8_t mask4{ 0x10 }; // hex for 0001 0000
		constexpr std::uint8_t mask5{ 0x20 }; // hex for 0010 0000
		constexpr std::uint8_t mask6{ 0x40 }; // hex for 0100 0000
		constexpr std::uint8_t mask7{ 0x80 }; // hex for 1000 0000
	*/

	// This method, the easier method, uses the bitwise left shift operator
	// to create an inline mask
	/*
		constexpr std::uint8_t mask0{ 1 << 0 }; // 0000 0001
		constexpr std::uint8_t mask1{ 1 << 1 }; // 0000 0010
		constexpr std::uint8_t mask2{ 1 << 2 }; // 0000 0100
		constexpr std::uint8_t mask3{ 1 << 3 }; // 0000 1000
		constexpr std::uint8_t mask4{ 1 << 4 }; // 0001 0000
		constexpr std::uint8_t mask5{ 1 << 5 }; // 0010 0000
		constexpr std::uint8_t mask6{ 1 << 6 }; // 0100 0000
		constexpr std::uint8_t mask7{ 1 << 7 }; // 1000 0000
	*/


	return 0;
}
#endif