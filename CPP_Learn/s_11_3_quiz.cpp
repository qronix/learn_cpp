#include "defineMain.h"

#ifdef __S11_3_Arrays_and_Loops__
#include <iterator>

int main()
{
	constexpr int array[]{4, 6, 7, 3, 8, 2, 1, 9, 5};

	int user_number{0};

	do
	{
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		std::cout << "Enter a number between 1-9: ";
		std::cin >> user_number;
		std::cout << '\n';
	}
	while (user_number < 1 || user_number > 9);

	int target_index{0};

	for (int index{0}; index < static_cast<int>(std::size(array)); ++index)
	{
		if (array[index] == user_number)
		{
			target_index = index;
		}

		std::cout << array[index] << " ";
	}

	std::cout << "\nThe number " << user_number << " has index " << target_index << std::endl;

	return 0;
}
#endif
