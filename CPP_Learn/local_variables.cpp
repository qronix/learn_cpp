#include <cstdio>

#include "defineMain.h"

#ifdef __LOCAL_VARIABLES__

//#define local_variables_exercise
#define local_variables_exercise_swap_utility

//Local variables have block scope, which means they are in scope from their point of definition to the end of the block they are defined within.
//A variable’s storage duration (usually just called duration) determines what rules govern when and how a variable will be created and destroyed. In most cases, a variable’s storage duration directly determines its lifetime.
//For example, local variables have automatic storage duration, which means they are created at the point of definition and destroyed at the end of the block they are defined in. For example:
#ifdef automatic_variables
int main()
{
	int i{5}; // i created and initialized
	double d{4.0}; // d created and initialized

	return 0;
} // i and d are destroyed here

// For this reason, local variables are sometimes called automatic variables.
#endif

#ifdef identifier_linkage
//Identifiers have another property named linkage. An identifier’s linkage determines whether other declarations of that name refer to the same object or not.
// Scope and linkage may seem similar; however, scope defines where a single declaration can be seen and used. Linkage defines whether multiple declarations refer to the same object or not.
//Local variables have no linkage, which means that each declaration refers to a unique object.For example :
int main()
{
	int x{ 2 }; // local variable, no linkage
	{
		int x{ 3 }; // this identifier x refers to a different object than the previous x
	}

	return 0;
}
#endif

#ifdef local_variables_exercise
// Section exercise
/*
 * Write a program that asks the user to enter two integers, one named smaller, the other named larger. If the user enters a smaller value for the second integer, use a block and a temporary variable to swap the smaller and larger values. Then print the values of the smaller and larger variables. Add comments to your code indicating where each variable dies. Note: When you print the values, smaller should hold the smaller input and larger the larger input, no matter which order they were entered in.

	The program output should match the following:

	Enter an integer: 4
	Enter a larger integer: 2
	Swapping the values
	The smaller value is 2
	The larger value is 4
 */

int main()
{
	int smaller{0};
	int larger{0};

	std::cout << "Enter an integer: " << std::endl;
	std::cin >> smaller;

	std::cout << "Enter a larger integer: " << std::endl;
	std::cin >> larger;

	if (larger < smaller)
	{
		int temp{larger};
		larger = smaller;
		smaller = temp;
	}

	printf("The smaller value is %d\n", smaller);
	printf("The larger value is %d\n", larger);

	return 0;
}

#endif

#ifdef local_variables_exercise_swap_utility
int main()
{
	std::cout << "Enter an integer:" << std::endl;
	int smaller{};
	std::cin >> smaller;

	std::cout << "Enter a larger integer:" << std::endl;
	int larger{};
	std::cin >> larger;

	if (larger < smaller)
	{
		std::swap(larger, smaller);
	}

	printf("The smaller value is %d\n", smaller);
	printf("The larger value is %d\n", larger);

	return 0;
}

#endif


// End of section question:
// What’s the difference between a variable’s scope, duration, and lifetime? By default, what kind of scope and duration do local variables have (and what do those mean)?

// scope: The area of a program in which a variable is accessible.

// duration: Duration, or storage duration, are the rules that govern when and how a variable will be created and destroyed. Usually, a variable's duration determines its lifetime.

// lifetime: A variables lifetime starts when its identifier is declared and ends when the identifier's containing scope ends

#endif
