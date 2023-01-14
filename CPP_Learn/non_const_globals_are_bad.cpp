#include <cstdio>

#include "defineMain.h"

#ifdef __NON_CONST_GLOBALS_ARE_BAD__
// The biggest reason non-const global variables are dangerous is because their values can
// be changed by any function, and there is no easy way to discern where or when a change
// will occur.

// Global variables also reduce modularity because functions become coupled to global variables.
// Whereas, a pure function which uses only its parameters is highly modular.

// Do not use global variables as "decision-point" (such as changing the flow of execution in a switch statement)
// variables. A program is not likely to break if a global variable holding an informational value changes
// (such as a username), but the same program is much more likely to break if a global variable is mutated
// and impacts HOW a program functions.

// Initialization of static variables (which includes global variables) happens as part of program startup, before
// execution of main(). This initialization occurs in two phases:
//
// The first phase is called static initialization. In this phase, global variables with constexpr initializers
// (this includes literals) are initialized to those values. Also, global variables without initializers are
// zero-initialized.
//
// The second phase is called dynamic initialization; this phase initializes global variables with non-constexpr
// initializers.

/*
 * Example of non-constexpr initializer
 *
 * int init(){
 *	return 10;
 * }
 *
 * int g_something{init()}; // non-constexpr initialization
 */

// Note: The order of initialization across different files is undefined and any could have its global variables
// initialized first. Therefore, dynamic initialization of globals should be avoided.

// If a non-const global must be used (which is exceedingly rare), these are some good tips to use to avoid trouble:

// - Prefix all non-namespaced global variables with "g_"
// - Putting all globals in a namespace is even better
// - Encapsulate non-const global variables by limiting the variable access to the file of definition via
//   static or const.
// - Provide external global "access functions" (getters / setters) to work with mutable globals
// - When writing a standalone function which uses a global variable, pass the global as function argument
//   instead of directly using the global within the function body. Doing this will help maintain modularity
//   by allowing the function to use a different value or perform the same logic on more than just the global	      variable.
#endif
