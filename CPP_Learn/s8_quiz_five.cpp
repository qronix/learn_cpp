#include "defineMain.h"
/*
 * https://www.learncpp.com/cpp-tutorial/chapter-8-summary-and-quiz/
 *
 * Section 8 Quiz Question 5
 */

// 5a) Write a function template named add that allows the users to add 2 values of the same type. The following program should run:
#ifdef __S8_Quiz_Ex_Five_A__
#include <iostream>

template <typename T>
T add(T x, T y)
{
	return x + y;
}

int main()
{
	std::cout << add(2, 3) << '\n';
	std::cout << add(1.2, 3.4) << '\n';

	return 0;
}
#endif

// 5b) Write a function template named mult that allows the user to multiply one value of any type (first parameter) and an integer (second parameter). The function should return the same type as the first parameter. The following program should run:
#ifdef __S8_Quiz_Ex_Five_B__
#include <iostream>

template <typename T>
T mult(T x, int y)
{
	return x * y;
}

int main()
{
	std::cout << mult(2, 3) << '\n';
	std::cout << mult(1.2, 3) << '\n';

	return 0;
}
#endif

// 5c) Write a function template named sub that allows the user to subtract two values of different types. The following program should run:
#ifdef __S8_Quiz_Ex_Five_C__
#include <iostream>

/*
//If C++20 capable, you can use an abbreviated function template instead
auto sub(auto x, auto y)
{
	return x - y;
}
*/

template <typename T, typename U>
auto sub(T x, U y)
{
	return x - y;
}

int main()
{
	std::cout << sub(3, 2) << '\n';
	std::cout << sub(3.5, 2) << '\n';
	std::cout << sub(4, 1.5) << '\n';

	return 0;
}
#endif
