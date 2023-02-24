#include "defineMain.h"

/*
 * LearnCPP Chapter 11 section 7 string view
 *
 * Example 4 - string_view works with non-null-terminated strings
 */

#ifdef __S11_7_String_View_EX4__
#include <iostream>
#include <string_view>
#include <iterator> // For std::size

int main()
{
	// No null-terminator
	char vowels[]{'a', 'e', 'i', 'o', 'u'};

	// Since vowels lacks a null-terminator, we can use
	// std::size and pass the array size to string_view
	// to get the appropriate end of the string
	std::string_view str{vowels, std::size(vowels)};

	std::cout << str << '\n';

	return 0;
}

#endif
