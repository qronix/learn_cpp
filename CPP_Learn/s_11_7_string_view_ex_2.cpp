#include "defineMain.h"

/*
 * LearnCPP Chapter 11 section 7 string view
 *
 * Example 2 - Demonstration that string_view is simply a view of a string and not a copy
 */

#ifdef __S11_7_String_View_EX2__
#include <iostream>
#include <string_view>

int main()
{
	char arr[]{"Gold"};
	std::string_view str{arr};

	std::cout << str << '\n'; // Gold

	// Mutate 'd' to 'f' in arr
	arr[3] = 'f';

	std::cout << str << '\n'; // Golf

	// The string "viewed" by string_view str has mutated, and since string_view
	// does not create a copy, the "view" has also mutated.

	return 0;
}
#endif

/*
 * Best practice

	Prefer std::string_view over std::string and C-style strings when you only need read-only access to a string (unless you can't guarantee the string being viewed will stay alive for the lifetime of the std::string_view, in which case you should prefer std::string).
 */
