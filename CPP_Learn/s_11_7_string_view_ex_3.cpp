#include "defineMain.h"

/*
 * LearnCPP Chapter 11 section 7 string view
 *
 * Example 3 - string_view manipulation functions
 *
 */

#ifdef __S11_7_String_View_EX3__
#include <iostream>
#include <string_view>

int main()
{
	std::string_view str{"Peach"};

	std::cout << str << '\n';

	// Ignore the first character
	str.remove_prefix(1);

	std::cout << str << '\n';

	// Ignore the last 2 characters
	str.remove_suffix(2);

	// Once the string view has been manipulated, it must be reassigned the source
	// string in order to regain full view of the string
	std::cout << str << '\n';

	std::cout << str.data() << '\n';

	return 0;
}
#endif
