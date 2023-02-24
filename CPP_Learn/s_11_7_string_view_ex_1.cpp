#include "defineMain.h"

/*
 * LearnCPP Chapter 11 section 7 string view
 *
 * Example 1 - Basic example of string_view
 */

#ifdef __S11_7_String_View_EX1__
#include <iostream>
#include <string_view>

int main()
{
	std::string_view str{"Trains are fast!"};

	std::cout << str.length() << '\n';
	std::cout << str.substr(0, str.find(' ')) << '\n'; // Trains
	std::cout << (str == "Trains are fast!") << '\n'; // 1

	// Since C++20
	std::cout << str.starts_with("Boats") << '\n'; // 0
	std::cout << str.ends_with("fast!") << '\n'; // 1

	std::cout << str << '\n'; // Trains are fast!

	return 0;
}
#endif
