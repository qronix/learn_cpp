#include "defineMain.h"

#ifdef __CONST_EXPR_EVAL__
// A constexpr function is a function whose return value may be computed at compile-time.

// To be eligible for compile-time evaluation, a function must have a constexpr return type and must
// not call any non-constexpr functions. Additionally, a call to the function must have constexpr
// arguments.

// Because constexpr functions may be evaluated at compile-time, the compiler must be able to see the full
// definition of the constexpr function at all points where the function is called. A constexpr function called in multiple files needs to have its definition included into each such file; this would normally violate the one-definition rule. However, to avoid violating the one-definition rule, constexpr functions are implicitly inline, which makes them exempt from the one-definition rule. As a result, constexpr functions are often defined in header files, so they can be #included into any translation unit which requires the full definition.

// Functions with a constexpr return value can also be evaluated at runtime, in which case they will return a non-constexpr result.
/*
 * [Runtime evaluation of constexpr function]
 *
 * constexpr int greater(int x, int y) {
 *	return (x > y ? x : y);
 * }
 */

// Because the return value of greater() is not a constexpr value, the function will be evaluated at runtime

// C++30 introduces the keyword consteval, which is used to indicate that a function must evaluate at compile-time, otherwise a compile error will result. Such functions are called immediate functions.

/*
 * [consteval keyword example]
 *
 * #include <iostream>
 *
 * consteval int greater(int x, int y){
 *	return (x > y ? x : y);
 * }
 *
 * int main(){
 *	constexpr int g{greater(5,6)}; // ok: will evaluate at compile-time
 *
 *	std::cout << greater(5,6) << " is greater!\n"; // ok: will evaluate at compile-time
 *
 *	int x{5}; // not constexpr
 *	std::cout << greater(x,6) << " is greater!\n"; // error: consteval functions must evaluate at compile-time
 *
 *	return 0;
 * }
 */
#endif
