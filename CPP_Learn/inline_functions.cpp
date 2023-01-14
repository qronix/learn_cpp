#include "defineMain.h"

#ifdef __INLINE_FUNCTIONS__
// Best practice: do not use the inline keyword to request inline expansion for functions

/*
 * In previous chapters, we mentioned that you should not implement functions (with external linkage) in header files, because when those headers are included into multiple .cpp files, the function definition will be copied into multiple .cpp files. These files will then be compiled, and the linker will throw an error because it will note that you’ve defined the same function more than once, which is a violation of the one-definition rule.

In lesson 6.9 -- Sharing global constants across multiple files (using inline variables), we noted that in modern C++, the inline concept has evolved to have a new meaning: multiple definitions are allowed in the program. This is true for functions as well as variables. Thus, if we mark a function as inline, then that function is allowed to have multiple definitions (in different files), as long as those definitions are identical.

In order to do inline expansion, the compiler needs to be able to see the full definition of an inline function wherever the function is called. Therefore, inline functions are typically defined in header files, where they can be #included into any code file that needs to see the full definition of the function.
 */
#endif
