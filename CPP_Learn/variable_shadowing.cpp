#include <cstdio>

#include "defineMain.h"

#ifdef __VARIABLE_SHADOWING__

int kittens{3};

int main()
{
	int apples{5}; //Outer block apples

	{
		// nested block
		printf("Outer block apples: %d\n", apples); // refers to outer scope apples

		int apples{0}; // apples is defined for the nested scope which causes outer block apples to be hidden

		// apples now refers to the nested block apples
		// the outer block apples is temporarily hidden
		// note: treating warnings as errors will result in a compilation error
		// since hiding is considered sketchy

		apples = 8; // assigns 8 to the nested block apples

		printf("Nested block apples: %d\n", apples);

		int kittens{8}; // shadows the global kitten variable

		++kittens; // increments local kittens

		--(::kittens); // uses no prefix scope operator to increment the global kitten variable
	} // nested block apples and kittens are destroyed

	printf("Outer block apples from outer scope: %d\n", apples);

	return 0;
}

// Best practice: Do not use variable shadowing
#endif
