#include "defineMain.h"

/*
 * LearnCPP Chapter 11 section 7 string_view
 *
 * Example 5 - Converting std::string_view to a C-style string
 */


#ifdef __S11_7_String_View_EX5__
#include <iostream>
#include <cstring>
#include <string_view>
#include <string>

int main()
{
	std::string_view sv{"balloon"};

	sv.remove_suffix(3);

	// Create a std::string from the std::string_view
	std::string str{sv};

	// Get the null-terminated C-style string.
	auto szNullTerminated{str.c_str()};

	// Pass the null-terminated string to the function that we want to use.
	std::cout << str << " has " << std::strlen(szNullTerminated) << " letter(s)\n";

	return 0;
}
#endif
