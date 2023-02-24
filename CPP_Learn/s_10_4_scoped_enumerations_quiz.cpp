#include "defineMain.h"

/*
 * Learn CPP Section 10.4 Quiz
 * https://www.learncpp.com/cpp-tutorial/scoped-enumerations-enum-classes/
 *
 * Question #1:
 * Define an enum class named Animal that contains the following animals: pig, chicken, goat, cat, dog, duck. Write a function named getAnimalName() that takes an Animal parameter and uses a switch statement to return the name for that animal as a std::string_view (or std::string if you’re using C++14). Write another function named printNumberOfLegs() that uses a switch statement to print the number of legs each animal walks on. Make sure both functions have a default case that prints an error message. Call printNumberOfLegs() from main() with a cat and a chicken. Your output should look like this:
 *
 * A cat has 4 legs.
 * A chicken has 2 legs.
 */
#ifdef __Scoped_Enumerations__
enum class Animal
{
	pig,
	chicken,
	goat,
	cat,
	dog,
	duck,
};

/*Accepts an animal of type <Animal> and returns the string_view name for the animal*/
constexpr std::string_view getAnimalName(Animal animal)
{
	// return the string view name of animal

	using enum Animal;

	switch (animal)
	{
	case pig: return "pig";
	case chicken: return "chicken";
	case goat: return "goat";
	case cat: return "cat";
	case dog: return "dog";
	case duck: return "duck";
	default:
		return "???";
	}
}

void printNumberOfLegs(Animal animal)
{
	// print number of legs for the animal
	using enum Animal;

	const std::string_view animalName{getAnimalName(animal)};

	switch (animal)
	{
	case pig:
	case goat:
	case cat:
	case dog:
		std::cout << "A " << animalName << " has 4 legs" << std::endl;
		break;
	case duck:
	case chicken:
		std::cout << "A " << animalName << " has 2 legs" << std::endl;
		break;
	default:
		std::cout << "I don't know how many legs that animal has." << std::endl;
	}
}

int main()
{
	printNumberOfLegs(Animal::cat);
	printNumberOfLegs(Animal::chicken);

	return 0;
}
#endif
