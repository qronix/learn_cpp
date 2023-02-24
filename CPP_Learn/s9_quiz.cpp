#include "defineMain.h"

// Section 9 quiz https://www.learncpp.com/cpp-tutorial/chapter-9-summary-and-quiz/

#ifdef __S9_Quiz__

/*
* Question 1
*
* For each of the following expressions on the right side of operator <<, indicate whether the expression is an lvalue or rvalue:
 */

// 1a) std::cout << 5; This is an rvalue as 5 is a literal

// 1b)
//
// int x { 5 };
// std::cout << x; // This is an lvalue because x is an identifier for the value of 5


// 1c)
//
// int x { 5 };
// std::cout << x + 1; // This is an rvalue because the unary + operator on x and 1 will yield the literal 6

// 1d)
//
// int foo() { return 5; }
// std::cout << foo();

//  This is an rvalue as the definition of foo() returns the literal 5, the compiler will replace the call to foo() with 5.
//   Solution from LearnCPP: The return value of a function (when returned by value) is an rvalue.

// 1e)
//
// int& max(int &x, int &y) { return x > y ? x : y; }
// int x{ 5 };
// int y{ 6 };
// std::cout << max(x, y); // This is an lvalue because max() is returning a reference to an integer


/*
 * Question 2 : What is the output of this program?
 *
 *
 * #include <iostream>

	int main()
	{
		int x{ 5 }; // x is initialized to 5
		int y{ 6 }; // y is initialized to 6

		int& ref{ x }; // ref is an int ref initialized as x (5)
		++ref; // inc ref and thus inc x (6)
		ref = y; // ref (x) now equals y (6) Note: references cannot be reseated, thus this will assign y to x
		++ref; // inc ref and thus inc x (7)

		std::cout << x << ' ' << y; // 7 6

		return 0;
	}
 */


/*
 * Question #3

	Name two reasons why we prefer to pass arguments by const reference instead of by non-const reference whenever possible.

	Ans: non-const ref will create a copy, and opens the value to mutation

	Correct ans:

	1. Yes, a non-const ref will open the value to possible mutation which we would like to avoid if possible.
	2. A non-const reference parameter can only accept a modifiable lvalue as an argument. A const reference-parameter can accept a modifiable lvalue, a non-modifiable lvalue, or an rvalue as an argument.
 */

/*
 * Question #4

	What is the difference between a const pointer and a pointer-to-const?

	Ans: A const pointer cannot be assigned a new address, a pointer to const means the value cannot be changed (... through the pointer)
 */
#endif
