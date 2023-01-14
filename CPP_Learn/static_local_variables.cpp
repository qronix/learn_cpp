#include <cstdio>

#include "defineMain.h"

#ifdef __STATIC_LOCAL_VARIABLES__
// Using the static keyword on a local variable changes its duration from automatic duration to static duration.
// This means the variable is now created at the start of the program and destroyed at the end of the program (just like a global variable)
// As a result, the static variable will retain its value even after it goes out of scope.

// Automatic duration local variable
void automatic_duration_increment_and_print()
{
	int value{0}; // automatic duration by default
	++value;
	printf("Automatic Duration Value: %d\n", value);
}

// Static duration local variable

// Though s_value leaves scope, the variable is not destroyed and thus maintains its value
void static_duration_increment_and_print()
{
	static int s_value{0}; // static locals usually start with s_
	++s_value;
	printf("Static Duration Value: %d\n", s_value);
}

int main()
{
	automatic_duration_increment_and_print(); // 1
	automatic_duration_increment_and_print(); // 1
	automatic_duration_increment_and_print(); // 1

	static_duration_increment_and_print(); // 1
	static_duration_increment_and_print(); // 2
	static_duration_increment_and_print(); // 3

	return 0;
}

// Best practice: Avoid static local variables unless the variable never needs to be reset
#endif
