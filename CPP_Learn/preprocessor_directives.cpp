#include "defineMain.h"

#if defined(__PRE_PROCESSOR_DIRECTIVES__)

// #ifdef is equivalent to #if defined()
// #ifndef is equivalent to #if !defined()
// #if 0 will always be skipped
// #if 1 will always be compiled
// #define FOO "jim" -> "jim" will be inserted wherever FOO exists

// Preprocessor directives only have an effect from the point of their declaration
// to the end of the file in which they were declared. Directives do not have an effect
// on any other file, unless included in a header file (such as "defineMain.h" as included above)

void willItWork() {
// This define directive will not remain scoped to just this function
// the preprocessor does not have an understanding of C++ concepts such as functions
	// and scope. Ergo, FOO will be replaced with 99 at ANY place FOO exists from the point
	// of definition onwards.
#define FOO 99
}

int main() {

#if defined(BOB)
	std::cout << "Bob was found\n";
#endif

#if !defined(BOB)
	std::cout << "Bob was not found\n";
#endif

#if 0
	std::cout << "This will never be executed or compiled\n";
#endif

#if 1
	std::cout << "This will be compiled and executed\n";
#endif

	return 0;
}

#endif