#include <iostream>
#include <string>

#if defined(__STRINGS__)
int main() {

	std::string myString{ "Herrrooo" };

	// use std::getline() to extract a string from stdin as
	// stdin will break on the first whitespace encountered

	std::cout << "Enter your full name: ";
	std::string fullName{};

	// getline expects an input buffer (std::cin) and 
	// std::ws is an input manipulator which tells std::cin to
	// ignore whitespace
	std::getline(std::cin >> std::ws, fullName);

	// Get length of string
	std::string myName{ "Alex" };
	std::cout << "Length of name: " << myName.length() << " characters\n";

	// string.length() returns an unsigned integral (usually of size_t).
	// To safely assign the integral value to an int variable, static_cast
	// it to avoid compiler issues and type coercion proplems

	const int myNameSize = static_cast<int>(myName.length());

	return 0;
}
#endif