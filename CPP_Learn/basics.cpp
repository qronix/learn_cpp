#include "defineMain.h"

#if defined(__BASICS__)

int main() {
	int a; // default initialization, undeterminate behavior
	int b = 3; // copy initializaion; copies value on RHS to variable on LHS; used for simple types

	// direct initialization; copy and direct initialization are essentially the same for simple types
	// however, direct initialization is more efficient for complicated types
	int c(4);

	// best practice, use braces whenever possible, to avoid data loss from coerced initialization
	// brace initialization (also called uniform or list initialization) is used for 
	// non-coerced assignment which prevents initializing a variable with a value it cannot safely hold
	// for example, initializing an int with a double, as all doubles will fit into an int

	int width{ 5 }; // direct brace initialization of value into variable width (preferred)
	int height = { 6 }; // copy brace initialization of value into height

	// value initialization; most cases the variable will be assigned zero (or empty) depending on
	// what is more appropriate for the variable type
	// best practice, initialize variables upon creation
	int depth{};

	// Best practice, \n is preferred over std::endl as std::endl usually performs unnecessary stdout flushing
	std::cout << "Enter two numbers, space delimited\n";

	int x{}; // best practice, zero-initialize variables which will later be assigned to by user input
	int y{};

	std::cin >> x >> y; // accept two space delimited integers from stdin

	std::cout << "You entered " << x << " and " << y << "\n";

	return 0;
}

#endif