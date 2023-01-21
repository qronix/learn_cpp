// Section 6 quiz question #1
//
// Fix the following program

#include <iostream>

#include "defineMain.h"

#ifdef __S6_Quiz_Ex_One__
int main()
{
	std::cout << "Enter a positive number: ";
	int num{};
	std::cin >> num;

	if (num < 0)
	{
		// Block scope was not used
		std::cout << "Negative number entered. Making entry positive.\n";
		num = -num;
	}

	std::cout << "You entered: " << num;

	return 0;
}
#endif
