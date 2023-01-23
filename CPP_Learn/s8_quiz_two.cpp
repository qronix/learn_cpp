#include "defineMain.h"

/*
 * https://www.learncpp.com/cpp-tutorial/chapter-8-summary-and-quiz/
 *
 * Section 8 Quiz Question 2
 *
 * Question 2a. Upgrade the following program using type aliases:
 */

#ifdef __S8_Quiz_Ex_Two__

// [Question 2a]
#include <iostream>

namespace constants
{
	inline constexpr double pi{3.14159};
}

using Degrees = double;
using Radians = double;

Radians convertToRadians(Degrees degrees)
{
	return degrees * constants::pi / 180;
}

int main()
{
	std::cout << "Enter a number of degrees: ";
	Degrees degrees{};
	std::cin >> degrees;

	Radians radians{convertToRadians(degrees)};
	std::cout << degrees << " degrees is " << radians << " radians.\n";

	radians = degrees;

	return 0;
}

// Question 2b. Building on quiz 2a, explain why the following statement will or won’t compile:
// radians = degrees;

// The statement will compile because 'Degrees' and 'Radians' are just aliases for type 'Double'. I should
// have just stuck with my first answer because I was right LOL.

#endif
