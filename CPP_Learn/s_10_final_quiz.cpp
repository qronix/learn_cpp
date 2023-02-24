#include "defineMain.h"

// LearnCPP Section 10 final quiz

/*
 * Question 1
 */
#ifdef  __S10_Final_Quiz_1__


enum class MonsterType
{
	ogre,
	dragon,
	spider,
	slime,
	orc,
};


const struct Monster
{
	MonsterType type;
	std::string_view name;
	int health;
};

std::string_view getMonsterTypeString(MonsterType mType)
{
	switch (mType)
	{
	case MonsterType::ogre: return "ogre";
	case MonsterType::dragon: return "dragon";
	case MonsterType::orc: return "orc";
	case MonsterType::slime: return "slime";
	case MonsterType::spider: return "spider";
	default: return "???";
	}
}

void printMonster(Monster& monster)
{
	std::string_view mon_type_name = getMonsterTypeString(monster.type);
	std::cout << "This " << mon_type_name << " is named " << monster.name << " and has " << monster.health << " health."
		<< std::endl;
}

int main()
{
	Monster ogre{MonsterType::ogre, "Torg", 145};
	Monster slime{MonsterType::slime, "Blurp", 23};

	printMonster(ogre);
	printMonster(slime);

	return 0;
}

#endif


/*
 * Question #2

Specify whether objects of each of the given types should be passed by value, const address, or const reference. You can assume the function that takes these types as parameters doesn’t modify them.
 */

// a) char - value [Ans] char is a fundamental type, so it should be passed by value.

// b) std::string - address [Ans] std::string has to create a copy of the string whenever it is copied. Pass it by const reference.

// c) unsigned long - reference [Ans] unsigned long is a fundamental type, so it should be passed by value.

// d) bool - value [Ans] bool is a fundamental type, so it should be passed by value.

// e) An enumerated type - reference [Ans] Enumerated types hold integral values (usually int). Since integral values are passed by value, enumerated types should be passed by value.

// f) - value [Ans] Position is a struct type and should be passed by const reference.
/*
 * struct Position
	{
	  double x{};
	  double y{};
	  double z{};
	};
 */

// g) reference [Ans] Although Player only contains a single int in its current state, which would make it fast to pass by value, more members will be added in the future. We don’t want to update every use of Player when that happens, so we pass it by const reference.
/*
 * struct Player
	{
	  int health{};
	  // The Player struct is still under development.  More members will be added.
	};
 */

// h) an object whose address is held in an int* - reference [Ans] int* is a pointer, so it should be passed by address.

// i) std::string_view - address [Ans] std::string_view does not create a copy of the string being viewed, and it is cheap to copy. Pass by value.


/*
 * Question #3

	Create a class template named Triad that has 3 members of the same template type. The program should produce the following result: [1, 2, 3][1.2, 3.4, 5.6]
 */
#ifdef __S10_Final_Quiz_3__

template <typename T>
struct Triad
{
	T first;
	T second;
	T third;
};

template <typename T>
void print(const Triad<T>& triad)
{
	std::cout << "[" << triad.first << "," << triad.second << "," << triad.third << "]";
}

int main()
{
	Triad t1{1, 2, 3}; // note: uses CTAD to deduce template arguments
	print(t1);

	Triad t2{1.2, 3.4, 5.6}; // note: uses CTAD to deduce template arguments
	print(t2);

	return 0;
}
#endif
