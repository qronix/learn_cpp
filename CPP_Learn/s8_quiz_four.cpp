#include "defineMain.h"

/*
 * https://www.learncpp.com/cpp-tutorial/chapter-8-summary-and-quiz/
 *
 * Question 4 - What is the output of this program and why?
 */

#ifdef __S8_Quiz_Ex_Four__
#include <iostream>

template <typename T>
int count(T)
// This is the same as int count(T x), except we're not giving the parameter a name since we don't use the parameter
{
	static int c{0};
	return ++c;
}

int main()
{
	std::cout << count(1) << '\n';
	std::cout << count(1) << '\n';
	std::cout << count(2.3) << '\n';
	std::cout << count<double>(1) << '\n';

	return 0;
}

// 1
// 2
// 1
// 2

// count<T> is a function template which accepts one unnamed and unused parameter of type T.
// Inside the definition of count<T>, int c is initialized as 0, however c is defined as static.
// Since c is static, the variable will remain within scope for the lifespan of the translation unit.
// Function templates instantiate a new instance for the function for each unique set of parameters the
// template function is called with. Therefore, count(1) initializes a function template with a single int
// parameter and c now holds the value of 1. Since c is static, and count(1) is also a secondary invocation of the int instance of count<T>,
// c persists its state throughout this instance and now holds the value of 2. When count(2.3) is called, a new instance of count<T> is instantiated
// which accepts a single parameter of type double. This new instance of count<T> with T being a double, creates a new
// and separate instance of static int c which again starts as 0 and is immediately incremented and evaluated as 1.
// The final call of count<double>(1) performs numeric promotion on int 1 and calls the count<T> double instance which
// again increments the static instance of c which now becomes 2. Therefore, the output is 1,2, 1,2.
#endif
