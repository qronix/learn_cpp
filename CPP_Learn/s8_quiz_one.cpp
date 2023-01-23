/*
 * https://www.learncpp.com/cpp-tutorial/chapter-8-summary-and-quiz/
 *
 * Section 8 Quiz Question One
 *
 * What type of conversion happens in each of the following cases? Valid answers are: No conversion needed, numeric promotion, numeric conversion, won’t compile due to narrowing conversion. Assume int and long are both 4 bytes.
 */

#include "defineMain.h"

#ifdef __S8_Quiz_Ex_One__

int main()
{
	int a{5}; // 1a
	int b{'a'}; // 1b
	int c{5.4}; // 1c
	int d{true}; // 1d
	int e{static_cast<int>(5.4)}; // 1e

	double f{5.0f}; // 1f
	double g{5}; // 1g

	// Extra credit section
	long h{5}; // 1h

	float i{f}; // 1i (uses previously defined variable f)
	float j{5.0}; // 1j
}

// My Answers

// 1a. No conversion needed
// 1b. Numeric conversion     Wrong.
// 1c. Narrowing conversion
// 1d. Numeric conversion	  Wrong.
// 1e. Narrowing conversion
// 1f. Numeric promotion
// 1g. Numeric promotion
// 1h. No conversion needed
// 1i. Won't compile
// 1j. Narrowing conversion


#endif
