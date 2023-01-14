#include <cstdio>

#include "defineMain.h"

#ifdef __GLOBAL_VARIABLES__
int g_x{}; //Variables declared outside of a function are global variables

// Best practice: Prefix global variables with "g_"
// Global variables have file scope (a.k.a. global or global namespace scope)
// Global variables are created when the program starts, and destroyed when it ends. This is called static duration. Variables with static duration are sometimes called static variables.
#endif
