#include "defineMain.h"

#ifdef __Unscoped_Enumerations_IO__

namespace color
{
	enum Color
	{
		black,
		red,
		blue,
		green,
		yellow,
		orange,
		purple,
	};
}


// Overload the << operator to print a Color
// The return type and parameter type are references to prevent copies from being made
std::ostream& operator<<(std::ostream& out, color::Color color)
{
	switch (color)
	{
	case color::black: out << "black";
		break;
	case color::red: out << "red";
		break;
	case color::blue: out << "blue";
		break;
	case color::green: out << "green";
		break;
	case color::yellow: out << "yellow";
		break;
	case color::orange: out << "orange";
		break;
	case color::purple: out << "purple";
		break;
	default: out << "????";
		break;
	}

	return out;
}

// Overload the >> operator to receive a Color
// The color is passed by reference so the function can modify its value
std::istream& operator>>(std::istream& in, color::Color& color)
{
	int input{};
	in >> input; // input an integer

	color = static_cast<color::Color>(input);

	return in;
}

int main()
{
	int shirt_color{};
	std::cout << "Please enter a shirt color: 0=black, 1=red, 2=blue, 3=green, 4=yellow, 5=orange, 6=purple \n";
	std::cin >> shirt_color;
	std::cout << "Your shirt is " << static_cast<color::Color>(shirt_color) << std::endl;

	return 0;
}

/*
 * Section 10.3 Quiz
 *
 * Question #1 True or false. Enumerators can be:
 *
 * Given an integer value - True
 * 
 * Given no explicit value - True
 *
 * Given a floating point value - FALSE
 * 
 * Given a negative value - True
 *
 * Given a non-unique value - True
 *
 * Initialized with the value of prior enumerators (e.g. magenta = red) - True
 *
 * 
 */
#endif
