#include "defineMain.h"

#include <iostream>
#include <string>

#if defined(__CONSTANTS__)
int main() {
	// symbolic constants (use the const keyword whaaaaaat?)
	// Constants must be initialized
	// myConstInt is a compile-time constant because its value CAN
	// be determined at compile-time
	const int myConstInt{ 4 };

	std::cout << "Enter your age: ";
	int age{};

	std::cin >> age;

	// myRuntimeConstant has a value which cannot be determined until runtime
	const int myRuntimeConstant{ age };

	// When declaring a const variable, the compiler will implicitly keep track
	// of whether or not it's a runtime or compile-time

	// C++ 11 introduced the keyword constexpr which ensures that a constant must be 
	// a compile-time constant

	// Value can be resolved at compile-time, okay
	constexpr double gravity{ 9.8 };

	// Cannot be resolved at compile-time, error
	constexpr int userAge{ age };

	// Best Practices

	/*
		- Any variable that should not be modifiable after initialization and whose initializer 
		is known at compile-time should be declared as constexpr.

		- Any variable that should not be modifiable after initialization and whose initializer 
		is not known at compile-time should be declared as const.
	*/


	// constexpr std::string is not completely supported in C++20
	// To use constexpr strings, use std::string_view instead
	using namespace std::literals;

	constexpr std::string_view myString{ "Hello there"sv };

	/*
		Best Practices:

		 - Function parameters for arguments passed by value should not be made const.
		 - Don't use const with return by value as the returned value is a copy
		 - Avoid using #define to create symbolic constants macros. 
		 Use const or constexpr variables instead.

	*/

	return 0;
}

#endif