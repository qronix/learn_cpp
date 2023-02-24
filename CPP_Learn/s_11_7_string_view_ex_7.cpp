#include "defineMain.h"

/*
 * LearnCPP Chapter 11 section 7 string_view
 *
 * Example 7 - string_view ownership issues
 */

#ifdef __S11_7_String_View_EX7__
#include <iostream>
#include <string>
#include <string_view>

std::string_view askForName()
{
	std::cout << "What is your name?\n";

	// Use a std::string, because std::cin needs to modify it
	std::string name{};
	std::cin >> name;

	// For demonstration purposes only. If we already have a std::string
	// there is no need to switch to a std::string_view
	std::string_view view{name};

	std::cout << "Hello " << view << '\n';

	return view;
} // name dies, and so does the string that name created, therefore, string_view is left with a dangling pointer to name

int main()
{
	std::string_view view{askForName()};

	// view is observing the dangling pointer to name since name died when
	// askForName exited scope
	std::cout << "Your name is " << view << '\n'; // Undefined behavior

	return 0;
}


#endif
