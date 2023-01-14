#include <iostream>
#include <iomanip>

#if defined(__FLOATS__)

int main() {
	// By default stdout will not print the fractional part of a number
	// thus, 5 is printed
	std::cout << 5.0 << "\n";

	// The f specifies this number as a floating point, by default
	// a fractional number is a double
	// this prints 11.3
	std::cout << 11.3f << "\n";

	// The number is printed in scientific notation
	std::cout << 23251.4154 << "\n";

	// stdout has a default precision of six digits, anything past that
	// is truncated

	// Prints 9.87654
	std::cout << 9.87654321f << '\n';

	// Prints 987.654
	std::cout << 987.654321f << '\n';

	// Prints 987654
	std::cout << 987654.321f << '\n';

	// Prints 987654e+006
	std::cout << 9876543.21f << '\n';

	// Prints 987654e-005
	std::cout << 0.0000987654321f << '\n';

	// Precision can be overridden using an output manipulator function:
	// std::setprecision(). Output manipulators define how data are output
	// and are defined in the iomanip header

	std::cout << std::setprecision(16); //show 16 digits of precision
	std::cout << 3.333333333333333333333333333333333333f << '\n';

	// The above will still output 3.333333253860474 as floats only have precision
	// to six - seven digits depending on the compiler

	/*
		Best Practices : 
			- Favor double over floats for better precision as the lack of precision in floats
			  will often lead to inaccuracies.
	*/
	


	return 0;
}

#endif