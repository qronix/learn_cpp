#include "defineMain.h"

/*
 * LearnCPP Chapter 11 section 9 pointer arithmetic and array indexing
 *
 * Example 1 - Manual array iteration via pointer arithmetic
 */


#ifdef __S11_8_String_View_EX1__

#include <iostream>
#include <iterator> // for std::size

bool isVowel(char ch)
{
	switch (ch)
	{
	case 'A':
	case 'a':
	case 'E':
	case 'e':
	case 'I':
	case 'i':
	case 'O':
	case 'o':
	case 'U':
	case 'u':
		return true;
	default:
		return false;
	}
}

int main()
{
	char name[]{"Mollie"};
	int arrayLength{static_cast<int>(std::size(name))};
	int numVowels{0};

	// We are using array length instead of array length - 1
	// because the end value of this, array due a lack of
	// sentinel termination, name[array length] does not contain an actual value
	// but a token which indicates the end of the array.
	// Accessing name[arrayLength] will still yield undefined behavior
	for (char* ptr{name}; ptr != (name + arrayLength); ++ptr)
	{
		if (isVowel(*ptr))
		{
			++numVowels;
		}
	}

	std::cout << name << " has " << numVowels << " vowels.\n";

	std::cout << "name[arrayLength]: " << static_cast<int>(name[arrayLength - 1]) << std::endl;

	return 0;
}

#endif
