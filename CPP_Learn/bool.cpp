#include <iostream>

#if defined(__BOOL__)
int main() {

	std::cout << true << "\n"; // Prints 1
	std::cout << false << "\n"; // Prints 0

	// Prints bools as true or false
	std::cout << std::boolalpha;

	// boolalpha can be disabled via
	std::cout << std::noboolalpha;

	// stdin only accepts 0 and 1 for false/true all other inputs cause
	// stdin to fail silently and zero out the variable which was to be assigned
	// from stdin. If std::boolalpha is enabled, stdin will accept true / false and
	// 0 and 1 will no longer be treated as booleans



	return 0;
}
#endif