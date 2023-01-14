#include <cstdio>

#include "defineMain.h"

#ifdef __EXTERNAL_LINKAGE__
// An identifier with external linkage can be seen and used both from the file in which
// it is defined, and from other code files (via a forward declaration). Identifiers with
// external linkage are truly "global" since they can be used anywhere in a program.

// Functions have external linkage by default. In order to call a function from another file
// than where it was defined, a forward declaration must be placed in any other file which
// would like to use the function. The forward declaration tells the compiler about the existence
// of the function, and the linker connects the function calls to the actual function definition


/*
 * [other_file.cpp]
 *
 * #include <cstdio>
 *
 * void say_hello() { // externally linked by default
 *	std::cout << "Hello" << std::endl;
 * }
 */


int g_x{2}; // non-constant globals are external by default

extern const int g_y{3}; // const globals can be defined as extern, making them external

// constexpr globals can be defined as extern, however this is useless because
// an identifier given external linkage via extern must be forward declared in order
// to be used. constexpr variables CANNOT be forward declared because the compiler needs
// to know the value of the constexpr variable at compile time. If the value of the constexpr
// variable is defined in another file, the compiler has no visibility on the value defined in
// the other file.
extern constexpr int g_z{4};

void say_hello(); // forward declaration for say_hello from other_file.cpp

// To make use of an externally linked constant global variable a forward declaration must be used
// in the file wishing to make use of the external global variable.

/*
 * [another_file.cpp]
 *
 * extern const int g_serial{2424242};
 */

extern const int g_serial; // forward declaration for g_serial from another_file.cpp

// WARNING:
// If you want to define an uninitialized non-const global variable, do not use the extern keyword, otherwise C++ will think you’re trying to make a forward declaration for the variable.

// Note that function forward declarations don’t need the extern keyword -- the compiler is able to tell whether you’re defining a new function or making a forward declaration based on whether you supply a function body or not. Variables forward declarations do need the extern keyword to help differentiate variables definitions from variable forward declarations 

int main()
{
	say_hello(); // linker will connect this call to the function definition

	return 0;
}

// Technically, in C++, all global variables have “file scope”, and the linkage property controls whether they can be used in other files or not.

// The term “file scope” is more often applied to global variables with internal linkage, and “global scope” to global variables with external linkage (since they can be used across the whole program, with the appropriate forward declarations).


// End of section question

// What’s the difference between a variable’s scope, duration, and linkage? What kind of scope, duration, and linkage do global variables have?

// Scope: Where the variable is accessible, could be global (whole program), file (whole file), block, nested block

// Duration: The rules which determine where the variable is defined and destroyed

// Linkage: Can the variable be seen from other files? If so, then the variable is externally linked, otherwise the variable is internally linked

// Global variables have global scope (aka, file scope), which means they can be accessed from the point of declaration to the end of the file in which they are declared.

// Global variables have static duration, which means they are created when the program is started, and destroyed when the program ends.

// Global variables can have either internal or external linkage, via the static and extern keywords respectively.

#endif
