#include "defineMain.h"

/*
 * LearnCPP Chapter 11 section 4 std::sort()
 *
 * Sorting arrays using the standard library sort method
 */

#ifdef __S11_4_STD_Sort__
#include <algorithm> // for std::sort
#include <iostream>
#include <iterator> // for std::size

int main()
{
	int array[]{30, 50, 20, 10, 40};

	// Sort using standard sort
	std::sort(std::begin(array), std::end(array));

	// Print sorted array for validation
	for (int index{0}; index < static_cast<int>(std::size(array)); ++index)
	{
		std::cout << array[index] << ' ';
	}

	std::cout << '\n';

	return 0;
}
#endif
