#include "defineMain.h"

#ifdef __FUNCTIONS__

int getNumberFromUser() {
	int value{};

	std::cout << "Enter a number: ";
	std::cin >> value;

	return value;
}


int main() {

	int result{ getNumberFromUser() };

	std::cout << "\nYou entered: " << result;

	return 0;
}

#endif 