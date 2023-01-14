#include "defineMain.h"

#ifdef __SCOPE_DURATION_LINKAGE_SUMMARY__
/*
 * [Scope Summary]
 *
 * An identifier's scope determines where the identifier can be accessed within the source code.
 *
 *	- Variables with block (local) scope can only be accessed within the block in which they are declared
 *	- Variables and functions with file (global) scope can be accessed from the point of declaration until
 *		the end of the file.
 *
 *
 * [Duration Summary]
 *
 * A variable's duration determines when it is created and destroyed.
 *
 *	- Variables with automatic duration are created at the point of definition, and destroyed when the block
 *		they are part of is exited. (local variables, function parameters)
 *
 *	- Variables with static duration are created when the program begins and are destroyed when the program		ends. (Global variables, static local variables)
 *
 *	- Variables with dynamic duration are created and destroyed by programmer request. (Dynamically allocated variables)
 *
 *
 * [Linkage Summary]
 *
 * An identifier's linkage determines whether multiple declarations of an identifier refer to the same entity (object, function, reference, etc..) or not.
 *
 * An identifier with no linkage means the identifier only refers to itself.
 *	- Local variables
 *	- User-defined type definitions (such as enums and classes) declared inside a block
 *
 * An identifier with internal linkage can be accessed anywhere within the file it is declared.
 *	- Static global variables (initialized or uninitialized)
 *	- Static functions
 *	- Const global variables
 *	- Functions declared inside an unnamed namespace
 *	- User-defined type definitions (enums / classes) declared inside an unnamed namespace
 *
 * An identifier with external linkage can be accessed anywhere within the file it is declared, or other files (via a forward declaration)
 *	- Functions
 *	- Non-const global variables (uninitialized or initialized)
 *	- Extern const global variables
 *	- Inline const global variables
 *	- User-defined type definitions (enums / classes) declared inside a namespace or in the global scope
 *
 *	Note: Functions have external linkage by default and can be made internal by using the static keyword.
 */
#endif
