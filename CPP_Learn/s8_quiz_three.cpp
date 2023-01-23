#include "defineMain.h"

/*
 * https://www.learncpp.com/cpp-tutorial/chapter-8-summary-and-quiz/
 *
 * Section 8 Quiz Question 3
 *
 * Question 3a. What is the output of this program and why?
 */

#ifdef __S8_Quiz_Ex_Three_A__

// [Question 3a]
#include <iostream>

void print(int x)
{
	std::cout << "int " << x << '\n';
}

void print(double x)
{
	std::cout << "double " << x << '\n';
}

int main()
{
	short s{5};
	print(s);

	return 0;
}

// 5, The compiler matches the first print() function as a numerical promotion (short to int) which is preferable over a numeric conversion (short to double)

#endif

// 3b) Why won’t the following compile?

#ifdef __S8_Quiz_Ex_Three_B__
#include <iostream>

void print()
{
	std::cout << "void\n";
}

void print(int x = 0)
{
	std::cout << "int " << x << '\n';
}

void print(double x)
{
	std::cout << "double " << x << '\n';
}

int main()
{
	print(5.0f);
	print();

	return 0;
}

// Because the overloaded print() function matches print() and print(int x=0) thus resulting in an ambiguous function call which
// results in a compiler error
#endif


// 3c) Why won’t the following compile?
#ifdef __S8_Quiz_Ex_Three_C__
#include <iostream>

void print(long x)
{
	std::cout << "long " << x << '\n';
}

void print(double x)
{
	std::cout << "double " << x << '\n';
}

int main()
{
	print(5);

	return 0;
}

// Because 5 is type int and converting an int to a long or double is a numeric conversion; this will render the compiler unable to determine which function is a better match.

// Error (active)	E0308	more than one instance of overloaded function "print" matches the argument list
#endif
