#include "defineMain.h"

#include <iostream>
#include <cstdint>
#include <bitset>

#if defined(__BIT_MASK_PRACTICE__)
int main() {

	// bitmasks for RGBA
	constexpr std::uint32_t redBits{ 0xFF000000 };
	constexpr std::uint32_t greenBits{ 0x00FF0000 };
	constexpr std::uint32_t blueBits{ 0x0000FF00 };
	constexpr std::uint32_t alphaBits{ 0x000000FF };

	std::cout << "Enter a 32-bit RGBA color value in hexadecimal (e.g. FF7F3300): ";
	std::uint32_t pixel{};
	std::cin >> std::hex >> pixel;

	std::uint8_t redHex{ static_cast<std::uint8_t>((pixel & redBits) >> 24) };
	std::uint8_t greenHex{ static_cast<std::uint8_t>((pixel & greenBits) >> 16) };
	std::uint8_t blueHex{ static_cast<std::uint8_t>((pixel & blueBits) >> 8) };
	std::uint8_t alphaHex{ static_cast<std::uint8_t>(pixel & alphaBits) };

	std::cout << "Your color contains: \n";
	//std::cout << std::hex; // displays hex values, or defaults to decimal rgba values
	std::cout << static_cast<int>(redHex) << " red\n";
	std::cout << static_cast<int>(greenHex) << " green\n";
	std::cout << static_cast<int>(blueHex) << " blue\n";
	std::cout << static_cast<int>(alphaHex) << " alpha\n";

	return 0;
}
#endif