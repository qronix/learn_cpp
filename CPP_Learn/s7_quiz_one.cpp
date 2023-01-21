#include <iostream>

#include "defineMain.h"
#include "s7_constants.h"

#ifdef __S7_Quiz_Ex_One__

double calculate_height(const double initial_height, const int seconds)
{
	const double distance_fallen{s7_constants::gravity * seconds * seconds / 2};
	const double height_now{initial_height - distance_fallen};

	if (height_now <= 0.0)
	{
		return 0.0;
	}

	return height_now;
}

bool calculate_and_print_height(const double initial_height, const int time)
{
	const double current_height{calculate_height(initial_height, time)};
	std::cout << "At " << time << " seconds, the ball is at height: " << current_height <<
		std::endl;

	return (current_height == 0.0);
}

int main()
{
	std::cout << "Enter the initial height of the tower in meters: ";
	double initial_height{};
	std::cin >> initial_height;

	int seconds{0};

	while (!calculate_and_print_height(initial_height, seconds))
	{
		++seconds;
	}


	return 0;
}

#endif
