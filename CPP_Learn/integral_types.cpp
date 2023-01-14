#include "defineMain.h"

#include <cstdint> //for fixed-width integers
#include <iostream>

#if defined(__INTEGRAL_TYPES__)

int main() {

	/*
		Fixed-width integers:
		
		To address the problem of integer values having uncertain ranges
		(since only a mimimum size is guaranteed by C++), the C99 standard
		defined a set of fixed-width integers (stdint.h) that are guaranteed
		to be the same size on any architecture.

		C++ officially adopted fixed-width integers as part of C++11; these
		integer types can be accessed via <cstdint>, and are defined within the
		std namespace.
	*/

	std::int8_t a; //one byte signed, treated like a signed char on many systems
	std::uint8_t b; // one byte unsigned, treated like an unsigned char on many systems

	std::int16_t c; // two bytes signed
	std::uint16_t d; // two bytes unsigned

	std::int32_t e; // four bytes signed
	std::uint32_t f; // four bytes unsigned

	std::int64_t g; // eight bytes signed
	std::uint64_t h; // eight bytes unsigned

	/*
		First, the fixed-width integers are not guaranteed to be defined on all architectures.
		They only exist on systems where there are fundamental types matching their widths and 
		following a certain binary representation. Your program will fail to compile on any 
		such architecture that does not support a fixed-width integer that your program is 
		using. However, given that most modern architectures have standardized around 
		8/16/32/64-bit variables, this is unlikely to be a problem unless your program needs 
		to be portable to some exotic mainframe or embedded architectures.

		Second, if you use a fixed-width integer, it may be slower than a wider type on some
		architectures. For example, if you need an integer that is guaranteed to be 32-bits, 
		you might decide to use std::int32_t, but your CPU might actually be faster at 
		processing 64-bit integers. However, just because your CPU can process a given type 
		faster doesn’t mean your program will be faster overall -- modern programs are often 
		constrained by memory usage rather than CPU, and the larger memory footprint may slow 
		your program more than the faster CPU processing accelerates it. It’s hard to know 
		without actually measuring.
	*/

	/*
		To address the above downsides of fixed-width integers, C++ defines two alternate
		sets of integers which are guaranteed to be defined

		The fast types (std::int_fast#_t and std::uint_fast#_t) provide the fastest 
		signed/unsigned integer type with a width of at least # bits 
		(where # = 8, 16, 32, or 64). For example, std::int_fast32_t will give you the 
		fastest signed integer type that’s at least 32 bits.

		The least types (std::int_least#_t and std::uint_least#_t) provide the smallest 
		signed/unsigned integer type with a width of at least # bits (where # = 8, 16, 32, or 64). For example,
		std::uint_least32_t will give you the smallest unsigned integer type that’s at least 
		32 bits.
	*/

	std::int_least8_t i;
	std::int_least16_t j;
	std::int_least32_t k;
	std::int_least64_t l;

	std::int_fast8_t m;
	std::int_fast16_t n;
	std::int_fast32_t o;
	std::int_fast64_t p;

	/*
		Integral best practices:

		 - Due to an oversight in the C++ specification, most compilers define and treat 
		 std::int8_t and std::uint8_t (and the corresponding fast and least fixed-width types) 
		 identically to types signed char and unsigned char respectively. This means these
		 8-bit types may (or may not) behave differently than the rest of the fixed-width
		 types, which can lead to errors. This behavior is system-dependent, so a program 
		 that behaves correctly on one architecture may not compile or behave correctly on 
		 another architecture.

		 - For consistency, it’s best to avoid std::int8_t and std::uint8_t 
		 (and the related fast and least types) altogether (use std::int16_t or 
		 std::uint16_t instead).

		 - Prefer int when the size of the integer doesn’t matter (e.g. the number will always fit within the range of a 2-byte signed integer). For example, if you’re asking the user to enter their age, or counting from 1 to 10, it doesn’t matter whether int is 16 or 32 bits (the numbers will fit either way). This will cover the vast majority of the cases you’re likely to run across.
		 - Prefer std::int#_t when storing a quantity that needs a guaranteed range.
		 - Prefer std::uint#_t when doing bit manipulation or where well-defined wrap-around 
			behavior is required.

		 - Avoid:
			- Unsigned types for holding quantities
			- The 8-bit fixed-width integer types
			- The fast and least fixed-width types
			- Any compiler-specific fixed-width integers -- for example, Visual Studio defines __int8, __int16, etc…
	
	*/

	return 0;
}

#endif