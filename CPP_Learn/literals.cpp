#include "defineMain.h"

#include <bitset> // for std::bitset
#include <iostream>
#include <string> // for std::string
#include <string_view> //for std::string_view

#if defined(__LITERALS__)
int main() {

	// Provides access to the s and sv suffixes
	// one of the only instances where 'using' an entire 
	// namespace is permissible
	using namespace std::literals;

	// number w/o suffix is type int by default
	std::cout << 5;

	// suffix of u or U is unsigned
	std::cout << 5u;

	// suffix of l or L is long
	std::cout << 5L;

	// floating point w/o suffix is double by default
	std::cout << 5.0;

	// suffix of f is float
	std::cout << 5.0f;

	// Causes a compile error because no suffix defaults to double and not float

	float myFloat{ 4.1 };

	// A C-style string literal
	std::cout << "Hello, world!\n";

	// C++ will concatenate sequential string literals
	std::cout << "Hello, " "world!\n";

	// no suffix is a C-style string literal
	std::cout << "foo\n";

	// s suffix is a std::string literal
	std::cout << "goo\n"s;

	// sv suffix is a std::string_view literal
	std::cout << "moo\n"sv;

	// base 10 decimal
	int x{ 12 }; 

	// base 8 octal
	int y{ 012 };

	// base 16 hex
	int z{ 0xf };

	// Prior to C++ 14, there was not a way to assign a binary literal, thus
	// hex was used as a workaround:

	int bin{};

	bin = 0x0001; // assign binary 0000 0000 0000 0001 to bin

	// C++ 14 binary literals

	int binNew{};

	binNew = 0b1; // assign binary 0000 0000 0000 0001 to binNew
	binNew = 0b1010; // assign binary 0000 0000 0000 1010 to binNew

	// C++ 14 also add the ability to use a quotation mark (') as a digit separator

	int binSep{ 0b1011'0010 };

	long value{ 2'132'673'462 };

	int myValue{ 40 };

	std::cout << myValue << '\n'; // decimal by default

	std::cout << std::hex << myValue << '\n'; // hexadecimal
	std::cout << myValue << '\n'; // still hexadecimal

	std::cout << std::oct << myValue << '\n'; // octal
	std::cout << std::dec << myValue << '\n'; // back to decimal

	std::cout << myValue << '\n'; // still decimal


	// std::cout does not have the capability to print binary built-in
	// C++ provides the standard library std::bitset to do this
	// using the header <bitset>, we can use std::bitset and tell std::bitset
	// how many bits we want to store. The number of bits to store must be a 
	// compile time constant.

	// std::bitset<8> means we want to store 8 bits
	std::bitset<8> bin1{ 0b1100'0011 }; // binary literal for binary 1100 0011
	
	std::bitset<8> bin2{ 0xC5 }; //hexadecimal literal for binary 1100 0101

	std::cout << bin1 << ' ' << bin2 << '\n';
	std::cout << std::bitset<4>{0b1010} << '\n'; // create a temporary bitset and print it

	return 0;
}

#endif
