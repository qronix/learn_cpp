#include <iostream>


#if defined(__TYPE_CONVERSION__)
int main() {

	// static_cast<new_type> will explicitly convert a value from
	// its current type, to new_type 
	static_cast<int>(5.5);

	char ch{ 'a' };

	// The argument passed to static_cast is evaluated and then converted
	// not converted and assigned. Meaning, ch will retain the value of 'a'
	// and not ASCII 97
	static_cast<int>(ch);

	// Warning: static_cast does not do any range checking and casting between
	// signed and unsigned can lead to unpredictable results
	return 0;
}
#endif