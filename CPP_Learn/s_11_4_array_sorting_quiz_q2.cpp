#include "defineMain.h"


/*
 * LearnCPP Chapter 11 section 4 array sorting quiz question 2
 *
 * Question #2

	Rewrite the selection sort code above (s_11_4_std_sort.cpp) to sort in descending order (largest numbers first).
 */

#ifdef __S11_4_Quiz_Q2__
#include <iostream>
#include <iterator> // for std::size

int main()
{
	int array[]{30, 50, 20, 10, 40};
	constexpr int length{static_cast<int>(std::size(array))};

	for (int startIndex{0}; startIndex < length - 1; ++startIndex)
	{
		// Assume first index is largest
		int largestIndex{startIndex};

		for (int currentIndex{startIndex + 1}; currentIndex < length; ++currentIndex)
		{
			if (array[currentIndex] > array[largestIndex])
			{
				largestIndex = currentIndex;
			}
		}

		std::swap(array[startIndex], array[largestIndex]);
	}

	// Print array for validation
	for (int index{0}; index < length; ++index)
	{
		std::cout << array[index] << ' ';
	}

	std::cout << '\n';

	return 0;
}
#endif
