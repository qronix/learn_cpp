#include "defineMain.h"

#ifdef __FUNCTION_TEMPLATES__
// Function templates allow us to create a "template" (no kidding) for a function
// this allows our function template to accept a wide range of parameter types
// without us having to create a new overloaded function for each set of parameters

/*
 * [Overloaded Function Example]
 *
 * int add(int x, int y){
 *	return x + y;
 * }
 *
 * double add(double x, double y){
 *	return x + y;
 * }
 *
 * float add(float x, float y){
 *	return x+y;
 * }
 *
 * We can see this is becoming repetitive and violating the DRY principle
 */

// So, we can use function templates to handle these situations for us!

// We use the template decorator to inform the compiler the following function definition
// will be a template and is using type T for its return type and parameter types
// Since this function is a template which accepts only type T, we can refer to it as add<T,T>
template <typename T>
T add(T x, T y)
{
	return x + y;
}

template <typename T, typename U>
T add_and_print(T x, T y, U message)
{
	std::cout << message << std::endl;

	return x + y;
}

int add(int x, int y)
{
	std::cout << "This is not a template\n";
	return x + y;
}

int main()
{
	// We can omit the type, but since the type is specified, the compiler will match this add() only against
	// template functions.
	const int result = add<int>(4, 5);
	printf("add(4,5): %d\n", result);

	// Angled brackets are used, so the compiler matches this call against
	// template functions only.
	const auto result_template = add<>(4.5, 6.7);
	printf("Type omitted template function call: %f\n", result_template);

	// No brackets are used, so the compiler matches against BOTH non-template and template functions
	const auto result_ambiguous = add(4, 6);
	printf("Ambiguous call: %d\n", result_ambiguous);

	const int second_result = add_and_print<int, std::string>(7, 8, "This is a template!");
	printf("add_and_print(7,8): %d\n", second_result);

	return 0;
}

#endif
