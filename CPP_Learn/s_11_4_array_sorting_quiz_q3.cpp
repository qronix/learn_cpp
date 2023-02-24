#include "defineMain.h"

/*
 * LearnCPP Chapter 11 section 4 array sorting quiz question 3
 *
 * Question #3:
 *
 * Implement unoptimized bubble sort
 *
 * Unoptimized bubble sort performs the following steps to sort an array from smallest to largest:
   A) Compare array element 0 with array element 1. If element 0 is larger, swap it with element 1.

   B) Now do the same for elements 1 and 2, and every subsequent pair of elements until you hit the end of the array. At this point, the last element in the array will be sorted.

   C) Repeat the first two steps again until the array is sorted.
 * 
 * Hint: If we're able to sort one element per iteration, that means we'll need to iterate roughly as many times as there are numbers in our array to guarantee that the whole array is sorted.
 *
 * Hint: When comparing pairs of elements, be careful of your array's range.
 */

#ifdef __S11_4_Quiz_Q3__
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

	// Yaaaay Bubble Sort
	for (int count{1}; count < length; ++count)
	{
		for (int i{0}; i < length - 1; ++i)
		{
			if (i + 1 <= length - 1 && array[i] > array[i + 1])
			{
				std::swap(array[i], array[i + 1]);
			}
		}
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
