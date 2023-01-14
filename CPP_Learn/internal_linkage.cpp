#include <cstdio>

#include "defineMain.h"

#ifdef __INTERNAL_LINKAGE__
// An identifier with internal linkage can be seen and used within a single file, but it is not accessible from other files
// (meaning it is not exposed to the linker). This means that if two files have identically named identifiers with internal
// linkage, those identifiers will be treated as independent.

static int g_x;
// non-constant globals have external linkage by default, but can be given internal linkage via the static keyword

// The use of the static keyword above is an example of a storage class specifier, which sets both the name’s linkage and its storage duration (but not its scope). The most commonly used storage class specifiers are static, extern, and mutable. The term storage class specifier is mostly used in technical documentations.

const int g_y{1}; // const globals have internal linkage by default

constexpr int g_z{2}; // constexpr globals have internal linkage by default

// However, it’s worth noting that internal objects (and functions) that are defined in different files are considered to be independent entities (even if their names and types are identical), so there is no violation of the one-definition rule. Each internal object only has one definition.


// Linkage is a property of an identifier (not of a variable), function identifiers have the same linkage property that variable identifiers do. Functions default to external linkage, but can be set to internal linkage via the static keyword
static int add(int x, int y)
{
	return x + y;
}

int main()
{
	return 0;
}
#endif
