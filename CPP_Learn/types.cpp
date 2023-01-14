/*
	- integral type:
		- integral means "like an integer"
		- integral type applies to booleans, chars, enumerated types, and integers as 
			all of these are stored in memory as integers

	- Types will have a suffix of _t

	- C++ only guarantees a MINIMUM size for each type, the maximum size is dependent
		upon the compiler used, and/or the computer architecture.

	- C++ minimum type sizes:
		- bool :		1 byte
		- char :		1 byte (always exactly one byte)
		- wchar_t :		1 byte
		- char16_t :	2 bytes
		- char32_t :	4 bytes	
		- short	:		2 bytes	
		- int :			2 bytes	
		- long :	    4 bytes	
		- long long :	8 bytes	
		- float :		4 bytes	
		- double :		8 bytes	
		- long double : 8 bytes

	 - use the sizeof() operator to determine a data type size on a particular machine
		- sizeof(char) => 1 byte
		- sizeof() also works on variables => sizeof(x)

	 - integer types are signed by default, making the signed keyword redundant
	 - unsigned integer types can hold values of 2^n
	 - signed integer types can hold values of (2^(n-1)) - 1
	 - unsigned integer types should not be used as they cause two problems:
		- Subtracting an unsigned value from another unsigned value can result in
			a negative number; however, negative numbers are not able to be represented
			by unsigned integers. This limitation causes negative results to wrap-around
			(overflow) to the top of the unsigned integer range, producing undefined behavior.

		- The second issue can occur when mixing signed and unsigned integers in a mathematical
			operation. If a signed and unsigned integer are used, the signed integer is
			coerced to an unsigned integer, which can again cause wrapping-around (overflow)
			to the top of the integer range.

	- Best practices:
		- Favor signed over unsigned numbers for holding quantities (even if they should be
			non-negative) and for mathematical operations.
		- Do not mix signed and unsigned numbers.
		- Prefer int when the size of the integer doesn’t matter (e.g. the number will always fit within the range of a 2-byte signed integer). For example, if you’re asking the user to enter their age, or counting from 1 to 10, it doesn’t matter whether int is 16 or 32 bits (the numbers will fit either way). This will cover the vast majority of the cases you’re likely to run across.
		- Prefer std::int#_t when storing a quantity that needs a guaranteed range.
		- Prefer std::uint#_t when doing bit manipulation or where well-defined wrap-around behavior is required.

		- Avoid the following when possible:

			Unsigned types for holding quantities
			The 8-bit fixed-width integer types
			The fast and least fixed-width types
			Any compiler-specific fixed-width integers -- for example, Visual Studio defines __int8, __int16, etc…
*/