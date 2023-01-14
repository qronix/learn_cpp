// Project headers
#include "defineMain.h"
#include "geo_math.h"
#include "geo_utils.h"

// Std headers
#include <iostream>

#if defined(__HEADER_GUARDS__)

void getSquare() {
	std::cout << "The square is 16\n";
}

/*
	Because geo_math.h includes geo_utils.h, header_guards.cpp ends up with
	a double definition of getDiameter(), which violates the SDR (single definition rule).

	Without header guards, a compilation error will occur:
	
	"function 'void getDiameter(void)' already has a body

	Header guards can rectify this and ensure only one definition of getDiameter() is included

	Header guard best practices:

	- EVERY header file should have a header guard
	- Header guards by convention are named FILENAME_H
	- _ is used for spaces and punctuation
	- Header guards are in all caps
	- At minimum, a header guard should be named FILENAME_H; however,
		conflicts can still arise in large projects where header files might
		share names due to locality. To avoid issues in larger projects, and to get
		in the habit of this best practice, it is recommended that header guard names
		take one of the forms of:

		- <PROJECT>_<PATH>_<FILE>_H
		- <FILE>_<LARGE RANDOM NUMBER>_H
		- <FILE>_<CREATION DATE>_H

	- #pragma once is essentially the same as a header guard, however, this directive is not
		an official part of the C++ language, and as such, does not guarantee portability;
		ergo, using the header guard idiom over the #pragma once directive is preferred to ensure
		maximum compatibility and portability.
*/
int main() {

	getSquare();

	return 0;
}

#endif
