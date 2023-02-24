#include "defineMain.h"

/*
 * https://www.learncpp.com/cpp-tutorial/struct-passing-and-miscellany/
 *
 * Learn CPP chapter 10 section 8 quiz
 */


/*
 * Question #1

	You are running a website, and you are trying to keep track of how much money you make per day from advertising. Declare an advertising struct that keeps track of how many ads you’ve shown to readers, what percentage of ads were clicked on by users, and how much you earned on average from each ad that was clicked. Read in values for each of these fields from the user. Pass the advertising struct to a function that prints each of the values, and then calculates how much you made for that day (multiply all 3 fields together).
 */
#ifdef __S10_8_Quiz_Ex_One
struct Advertising
{
	int ads_shown;
	double ads_clicked_percentage;
	double avg_revenue_per_ad;
};

void printAndCalculateAdRevenue(Advertising& advertising)
{
	printf("\nAds shown: %d, Ad click percentage: %f, Avg revenue per ad: %f", advertising.ads_shown,
	       advertising.ads_clicked_percentage, advertising.avg_revenue_per_ad);

	const double total_ad_revenue = advertising.ads_shown * advertising.ads_clicked_percentage / 100 * advertising.
		avg_revenue_per_ad;

	printf("\nTotal ad revenue:$ %f", total_ad_revenue);
}

int main()
{
	Advertising advertising{};

	std::cout << "Number of ads shown: ";
	std::cin >> advertising.ads_shown;

	std::cout << "\nAd click percentage: ";
	std::cin >> advertising.ads_clicked_percentage;

	std::cout << "\nAvg revenue per ad: ";
	std::cin >> advertising.avg_revenue_per_ad;

	printAndCalculateAdRevenue(advertising);

	return 0;
}
#endif


/*
 * Question #2

Create a struct to hold a fraction. The struct should have an integer numerator and an integer denominator member.

Write a function to read in a Fraction from the user, and use it to read-in two fraction objects. Write another function to multiply two Fractions together and return the result as a Fraction (you don’t need to reduce the fraction). Write another function that prints a fraction.
 */
#ifdef __S10_8_Quiz_Ex_Two
struct Fraction
{
	int numerator{0};
	int denominator{1};
};

void printFraction(Fraction& fraction)
{
	std::cout << fraction.numerator << '/' << fraction.denominator << std::endl;
}

Fraction getFraction()
{
	Fraction temp{};

	std::cout << "\nEnter a value for the numerator: ";
	std::cin >> temp.numerator;
	std::cout << "\nEnter a value for the denominator: ";
	std::cin >> temp.denominator;

	return temp;
}

Fraction multiplyFractions(Fraction& fractionOne, Fraction& fractionTwo)
{
	Fraction temp{
		fractionOne.numerator * fractionTwo.numerator,
		fractionOne.denominator * fractionTwo.denominator
	};

	return temp;
}

int main()
{
	Fraction fractionOne{getFraction()};
	Fraction fractionTwo{getFraction()};

	Fraction fractionProduct{multiplyFractions(fractionOne, fractionTwo)};

	std::cout << "Your fractions multiplied together: ";
	printFraction(fractionProduct);

	return 0;
}

#endif

/*
 * Question #3

In the solution to the prior quiz question, why does getFraction() return by value instead of by reference?
 */
#ifdef __S10_8_Quiz_Ex_Three
/*
 * So a dangling reference is not being returned.
 *
 * LearnCPP Answer:
 *
 * Because our temp Fraction is a local variable, it will go out of scope at the end of the function. If we were to return temp as reference, we’d return a dangling reference back to the caller.
 */
#endif
