#include "defineMain.h"

#ifdef __Unscoped_Enumerations__
// Section 10.2 Question #1: Define an enumerated type named MonsterType to choose between the following monster races: orcs, goblins, trolls, ogres, and skeletons.

enum MonsterType
{
	orc,
	goblin,
	troll,
	ogre,
	skeleton
};


// Section 10.2 Question #2: Put the MonsterType enumeration inside a namespace. Then, create a main() function and instantiate a troll. The program should compile.

namespace monster_type
{
	enum MonsterType
	{
		orc,
		goblin,
		troll,
		ogre,
		skeleton
	};
}

int main()
{
	const monster_type::MonsterType myMonster{monster_type::troll};

	return 0;
}
#endif
