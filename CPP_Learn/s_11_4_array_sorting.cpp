#include "defineMain.h"

/*
 * LearnCPP Chapter 11 section 4 array sorting
 *
 * Implementation of selection sort in C++
 */

#ifdef __S11_4_Array_Sorting__
#include <iostream> // For std::cout()
#include <iterator> // For std::size()

int main()
{
	int array[]{30, 50, 20, 10, 40};
	constexpr int length{static_cast<int>(std::size(array))};
	// Iterate over each array element except the final one which will already be sorted
	// by the time the loop finishes
	for (int startIndex{0}; startIndex < length - 1; ++startIndex)
	{
		// smallestIndex is the index of the smallest element encountered this iteration
		// Start by assuming the smallest index will be the first element of this iteration
		int smallestIndex{startIndex};

		// Then look for a smaller element in the rest of the array
		for (int currentIndex{startIndex + 1}; currentIndex < length; ++currentIndex)
		{
			// If we've found an element that is smaller than our previously found smallest
			if (array[currentIndex] < array[smallestIndex])
			{
				// Then keep track of it
				smallestIndex = currentIndex;
			}
		}

		// smallestIndex is now the smallest element in the remaining array
		// swap our start element with our smallest element (sorting it into the correct place)
		std::swap(array[startIndex], array[smallestIndex]);
	}

	// The whole array has been sorted, print the array for validation
	for (int index{0}; index < length; ++index)
	{
		std::cout << array[index] << ' ';
	}

	std::cout << '\n';

	return 0;
}

#endif
