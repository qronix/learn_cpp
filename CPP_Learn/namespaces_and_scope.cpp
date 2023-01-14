#include <iostream>

#include "defineMain.h"

#ifdef __NAMESPACES_AND_SCOPE__
/*
 * Namespaces allow us to group similar code together and
 * use similar names while preventing name collisions
 */


void print()
{
	std::cout << "We printing!" << std::endl;
}

namespace cat
{
	void talk()
	{
		std::cout << "The cat says MEOW!" << std::endl;
	}

	void print()
	{
		std::cout << "The cat is using the printer!" << std::endl;
	}

	void waste_printer_ink()
	{
		print(); //Calls print within the cat namespace

		//Using the scope resolution operator without an identifier causes the compiler to
		//try finding a matching declaration within the containing namespace, if no matching identifier is found
		//the compiler will the check each containing namespace in sequence to see if a match is found, with the
		//global namespace being checked last
		::print();
	}
}

//namespaces can even be declared across multiple files
//or even multiple times within the same file
//all declarations within the namespace are considered part
//of the namespace

namespace dog
{
	void chew()
	{
		std::cout << "Oh no! The dog is chewing your shoes!" << std::endl;
	}
}

namespace dog
{
	void talk()
	{
		std::cout << "The dog sayeth BARK!" << std::endl;
	}

	void bad_dog()
	{
		chew(); //We can call chew() since it was declared elsewhere within the same namespace
	}
}


//Namespaces can also be nested

namespace foo
{
	namespace goo
	{
		int add(int x, int y)
		{
			return x + y;
		}
	}
}


//C++ 17 standard nested namespace

namespace nest::egg
{
	void warm()
	{
		std::cout << "You warmed the egg!" << std::endl;
	}
}

int main()
{
	//With namespaces, we can call both talk functions scoped to their respective namespaces
	//without running into a name collision.
	//If we did not use namespaces, and simply called talk() (if talk was defined in cat.cpp and
	//dog.cpp) then we would experience a linker error similar to error LNK2019: unresolved external symbol void talk() blah blah blah
	cat::talk();
	dog::talk();
	dog::bad_dog();
	cat::waste_printer_ink();

	std::cout << foo::goo::add(2, 2) << std::endl;

	nest::egg::warm(); //C++ 17 nested namespace

	namespace bird_egg = nest::egg; //Alias for nest::egg nested namespace

	bird_egg::warm();

	return 0;
} // Alias bird_egg does not exist outside this scope
#endif

/*
  When you write a library or code that you want to distribute to others, always place your code inside a namespace. The code your library is used in may not follow best practices -- in such a case, if your library’s declarations aren’t in a namespace, there’s an elevated chance for naming conflicts to occur. As an additional advantage, placing library code inside a namespace also allows the user to see the contents of your library by using their editor’s auto-complete and suggestion feature.
 */
