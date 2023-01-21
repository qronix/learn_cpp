// Section 6 quiz question three

// Complete the following program by writing the passOrFail() function, which should return true for the first three calls, and false thereafter. Do this without modifying the main() function.

#include "defineMain.h"

#ifdef __S6_Quiz_Ex_Three__
#include <iostream>


bool passOrFail()
{
	static int count{0}; // static keyword keeps variable in scope until the translation unit is finished executing
	++count;

	return count <= 3;
}

int main()
{
	std::cout << "User #1: " << (passOrFail() ? "Pass\n" : "Fail\n");
	std::cout << "User #2: " << (passOrFail() ? "Pass\n" : "Fail\n");
	std::cout << "User #3: " << (passOrFail() ? "Pass\n" : "Fail\n");
	std::cout << "User #4: " << (passOrFail() ? "Pass\n" : "Fail\n");
	std::cout << "User #5: " << (passOrFail() ? "Pass\n" : "Fail\n");

	return 0;
}
#endif
