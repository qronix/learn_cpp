#include <cstdio>

#include "defineMain.h"

#ifdef __INLINE_VARIABLES__
// inline means "multiple definitions are allowed"
// Therefore, an inline variable is one that is allowed to be defined in multiple files
// without violating the one definition rule. Inline global variables have external linkage
// by default.

// The linker will consolidate all inline definitions of a variable into a single variable definition
// thus meeting the one definition rule. This allows us to define variables in a header file and have them
// treated as if there was only one definition in a .cpp file somewhere.

// Note: Variables defined in a header file are duplicated when included, unless they are defined (not declared) in a .cpp file; then only a single reference for the variable is included across all files, that
// being the definition in the .cpp file.

// Example: If you have a normal constant that is being #included into 10 translation units, without inline you will get 10 definitions. With inline, the compiler picks a single definition to represent the canonical definition resulting in only one definition and the saving of nine constants worth of memory (since nine duplicates have been eliminated)

// Inline variables have two primary restrictions which must be obeyed:
//
// 1. All definitions of the inline variable must be identical (otherwise, undefined behavior will result).
// 2. The inline variable definition (not a forward declaration) must be present in any file that uses the variable.

// Example usage:

/*
 * [constants.h]
 *
 * // define a namespace to hold constants
 * namespace constants {
 *	inline constexpr double pi {3.14159};
 *	inline constexpr double avogadro {6.0221413e23};
 *	inline constexpr double gravity {9.2};
 * }
 */

/*
 * [main.cpp]
 *
 * #include <iostream>
 *	
 * #include "constants.h"
 *
 * int main(){
 *	std::cout << "Enter a radius: ";
 *	int radius{};
 *	std::cin >> radius;
 *	std::cout << "The circumference is: " << 2.0 * radius * constants::pi << std::endl;
 *
 *	return 0;
 * }
 *
 */

// Now, using inline, we can include constants.h into as many translation units as we desire, but these variables will only be instantiated once and shared across all code files.

// Note: Like defining constants in a header file (without a corresponding .cpp file to hold the constants' definitions), the use of inline retains the downside of requiring every file that includes the constants header to be recompiled if any constant value is changed.

// Best practice: If you need global constants and you can use C++17, prefer defining inline constexpr global variables in a header file

// Reminder: Use std::string_view for constexpr strings.
#endif
