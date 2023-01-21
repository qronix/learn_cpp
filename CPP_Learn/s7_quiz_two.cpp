#include "defineMain.h"

#ifdef __S7_Quiz_Ex_Two__
#include <iostream>
#include <cassert>
#include <cmath>

bool isPrime(int x)
{
	// If x is negative, 0, or 1, the number is not prime

	if (x <= 1)
	{
		return false;
	}

	const int max_test{static_cast<int>(std::sqrt(x))};

	for (int test{2}; test <= max_test; ++test)
	{
		if (x % test == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	assert(!isPrime(0));
	assert(!isPrime(1));
	assert(isPrime(2));
	assert(isPrime(3));
	assert(!isPrime(4));
	assert(isPrime(5));
	assert(isPrime(7));
	assert(!isPrime(9));
	assert(isPrime(11));
	assert(isPrime(13));
	assert(!isPrime(15));
	assert(!isPrime(16));
	assert(isPrime(17));
	assert(isPrime(19));
	assert(isPrime(97));
	assert(!isPrime(99));
	assert(isPrime(13417));

	std::cout << "Success!\n";

	return 0;
}
#endif
