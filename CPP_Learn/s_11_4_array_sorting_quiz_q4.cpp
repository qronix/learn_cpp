#include "defineMain.h"

/*
 * LearnCPP Chapter 11 section 4 array sorting quiz question 4
 *
 * Question #4

	Add two optimizations to the bubble sort algorithm you wrote in the previous quiz question:

    Notice how with each iteration of bubble sort, the biggest number remaining gets bubbled to the end of the array. After the first iteration, the last array element is sorted. After the second iteration, the second to last array element is sorted too. And so on... With each iteration, we don't need to recheck elements that we know are already sorted. Change your loop to not re-check elements that are already sorted.

    If we go through an entire iteration without doing a swap, then we know the array must already be sorted. Implement a check to determine whether any swaps were made this iteration, and if not, terminate the loop early. If the loop was terminated early, print on which iteration the sort ended early.
 */

#ifdef __S11_4_Quiz_Q4__

#include <iostream>
#include <iterator> // For std::size

int main()
{
	int array[]{6, 3, 2, 9, 7, 1, 5, 4, 8};
	constexpr int length{static_cast<int>(std::size(array))};

	// Compare arr[i] with arr[i+1]
	// Swap arr[i] with arr[i+1] iff arr[i] > arr[i+1]
	// Repeat these actions for arr[i+1] and arr[i+2]
	// Continue for every subsequent pair until the end of the array
	// Now, the last element in the array will be sorted (it has bubbled to the end)
	// Repeat the comparison and swap until the array is sorted (i == n-1, since arr[n-1] is sorted)

	// Optimized Bubble Sort
	int sortedUpperBound = length - 1;
	int iterationCount = 1;

	for (int count{1}; count < length; ++count)
	{
		bool swapOccurred = false;

		for (int i{0}; i < sortedUpperBound; ++i)
		{
			if (array[i] > array[i + 1])
			{
				std::swap(array[i], array[i + 1]);
				swapOccurred = true;
			}
		}

		if (!swapOccurred)
		{
			std::cout << "Early termination on iteration " << iterationCount << std::endl;
			break;
		}

		--sortedUpperBound;
		++iterationCount;
	}

	// Print and validate array
	for (int i{0}; i < length; ++i)
	{
		std::cout << array[i] << ' ';
	}

	std::cout << '\n';

	return 0;
}

#endif
