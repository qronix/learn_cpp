#include "defineMain.h"

/*
 * LearnCPP Chapter 11 section 7 string_view
 *
 * Example 8 - The data() function and non-null-terminated strings
 *
 */

#ifdef __S11_7_String_View_EX8__
#include <iostream>
#include <string_view>

int main()
{
	std::string_view str{"balloon"}; // string_view assigns "balloon" to _MyData

	std::cout << "removing b\n";

	// remove the "b"
	str.remove_prefix(1); // _MyData pointer has shifted by sizeof str[0] and now contains "alloon"

	// remove the "oon"
	// _MyData remains "alloon" since this mutates the suffix,
	// instead, the value of str now has the size 3 (alloon - 3)
	// and the view of the string_view has changed to "all" (_MyData[0] - _MyData[2])
	str.remove_suffix(3);

	std::cout << "removing oon\n";

	// Remember the above does not modify the string, only the region
	// that str (string_view) is observing
	std::cout << str << " has " << std::strlen(str.data()) << " letters(s)\n";
	std::cout << "str is " << str << '\n';
	std::cout << "str.data() is " << str.data() << '\n';

	return 0;
}

#endif
