#include "defineMain.h"

#ifdef __Multiply_By_Two__

int main() {
	int integerToMultiply;
	const int MultiplyValue = 2;

	std::cout << "Enter an integer: ";
	std::cin >> integerToMultiply;

	std::cout << "itm: " << integerToMultiply << "\n";
	std::cout << "Double that number is: " << integerToMultiply * MultiplyValue << "\n";

	return 0;
}

#endif