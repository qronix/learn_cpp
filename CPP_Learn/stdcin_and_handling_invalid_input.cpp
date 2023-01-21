#include <iostream>
#include <limits>

#include "defineMain.h"

#ifdef __HANDLING_INVALID_INPUT__

// Ignore the maximum possible amount of input in the standard input buffer up and including a newline character
// This effectively flushes any remaining information out of the standard input buffer
void ignore_line()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

double get_double()
{
	// Loop until valid input is received
	while (true)
	{
		std::cout << "Enter a double value: ";
		double x{};
		std::cin >> x;

		// Check for failed input extraction
		if (!std::cin) // Has a previous extraction failed
		{
			// If input extraction fails, cin will go into "failure mode" and ignore any additional input
			// calling cin.clear() will reset the buffer to its normal operational mode
			std::cin.clear();
			// Flush the input buffer
			ignore_line();
			// Inform the user of the error
			std::cerr << "Invalid input, try again.\n";
		}
		else
		{
			ignore_line();

			return x;
		}
	}
}

char get_operator()
{
	// Loop until valid input is received
	while (true)
	{
		std::cout << "Enter one of the following: +, -, *, or /: ";
		char operation{};
		std::cin >> operation;
		// Flush any remaining buffer information since we only want a single character
		ignore_line();

		// Check if the input is valid
		switch (operation)
		{
		case '+':
		case '-':
		case '*':
		case '/':
			return operation;
		default:
			std::cerr << "Invalid input, try again.\n";
		}
	}
}

void print_result(const double x, const char operation, const double y)
{
	switch (operation)
	{
	case '+':
		std::cout << x << " + " << y << " is " << x + y << '\n';
		break;
	case '-':
		std::cout << x << " - " << y << " is " << x - y << '\n';
		break;
	case '*':
		std::cout << x << " * " << y << " is " << x * y << '\n';
		break;
	case '/':
		std::cout << x << " / " << y << " is " << x / y << '\n';
		break;
	default:
		std::cerr << "Something went wrong: print_result() received an invalid operator.\n";
	}
}

int main()
{
	const double x{get_double()};
	const char operation{get_operator()};
	const double y{get_double()};

	print_result(x, operation, y);

	return 0;
}
#endif
