#include "defineMain.h"

#ifdef __S11_2_Arrays__

namespace Farm
{
	enum Animals
	{
		chicken,
		dog,
		cat,
		elephant,
		duck,
		snake,
		max_animals,
	};
}

int main()
{
	double daily_temps[365]{0.0};
	int animal_legs[Farm::max_animals]{2, 4, 4, 4, 2, 0};

	std::cout << "An elephant has " << animal_legs[Farm::Animals::elephant] << " legs\n";

	return 0;
}
#endif
