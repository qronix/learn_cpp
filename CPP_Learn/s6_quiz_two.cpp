// Section 6 quiz question #2

// Write a file named constants.h that makes the following program run.
#include <iostream>
#include "defineMain.h"

#ifdef __S6_Quiz_Ex_Two__
#include "constants.h"

int main()
{
	std::cout << "How many students are in your class? ";
	int students{};
	std::cin >> students;


	if (students > constants::max_class_size)
		std::cout << "There are too many students in this class";
	else
		std::cout << "This class isn't too large";

	return 0;
}
#endif
