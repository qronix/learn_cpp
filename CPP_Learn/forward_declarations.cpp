#include "defineMain.h"

#ifdef __FORWARD_DECLARATIONS__

// This function prototype is a function forward declaration
// The prototype informs the compiler that add() exists and what
// its signature is. A function prototype is not a definition and
// if the function prototype body is not defined, a linker error will
// occur

int add(int x, int y);

int main() {
	int x{5};
	int y{6};

	// without the function prototype (forward declaration)
	// The compiler would raise an error stating 'add' : identifier not found
	// This happens because add() is defined after main()
	std::cout << x << " + " << y << " = " << add(x, y);

	return 0;
}

int add(int x, int y) {
	return x + y;
}

#endif