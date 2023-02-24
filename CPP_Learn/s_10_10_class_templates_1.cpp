#include "defineMain.h"

/*
 * LearnCPP chapter 10 section 10 class templates example one
 */
#ifdef __S10_10_Class_Templates_1__
#include <iostream>

template <typename T>
struct Pair
{
	T first{};
	T second{};
};

template <typename T>
constexpr T max(Pair<T> p)
{
	return (p.first > p.second ? p.first : p.second);
}

template <typename T, typename U>
constexpr void print(T first, U second)
{
	std::cout << "First: " << first << " Second: " << second << std::endl;
}

template <typename T, typename U>
struct Deduce
{
	T first;
	U second;
};

// Deduction guide for Deduce
// This is not required as of C++20
template <typename T, typename U>
Deduce(T, U) -> Deduce<T, U>;

int main()
{
	Pair<int> pairOne{1, 7};
	std::cout << max<int>(pairOne) << " is larger\n";

	Pair<double> pairTwo{1.4, 8.8};
	std::cout << max(pairTwo) << " is larger\n"; // Best practice, use template argument deduction

	// Class Template Argument Deduction (CTAD)
	print(1, 5);

	Deduce deduce{4, 5.6f};

	std::cout << "Deduce first: " << deduce.first << " deduce second: " << deduce.second << std::endl;

	return 0;
}

#endif
