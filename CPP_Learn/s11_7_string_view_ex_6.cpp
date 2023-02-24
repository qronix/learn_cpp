#include "defineMain.h"

/*
 * LearnCPP Chapter 11 section 7 string_view
 *
 * Example 6 - std::string_view and std::string conversions and expenses
 */

#ifdef __S11_7_String_View_EX6__
#include <iostream>
#include <string_view>
#include <string>

void printSV(std::string_view sv)
{
	std::cout << sv << '\n';
}

void printS(const std::string& s)
{
	std::cout << s << '\n';
}

int main()
{
	std::string s{"Hello, world"};
	std::string_view sv{s};

	// Pass to 'std::string_view parameter
	printSV(s); // ok: inexpensive conversion from std::string to std::string_view
	printSV(sv); // ok: inexpensive copy of std::string_view
	printSV("Hello, world"); // ok: inexpensive conversion of C-style string literal to std::string_view

	// pass to 'const std::string&' parameter
	printS(s); // ok: inexpensive bind to std::string argument
	//printS(sv); // compile error: cannot implicit convert std::string_view to std::string
	printS(static_cast<std::string>(sv)); // bad: expensive creation of std::string temporary
	printS("Hello, world"); // bad: expensive creation of std::string temporary

	return 0;
}

#endif
