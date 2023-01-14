#include "defineMain.h"

#include <iostream>
#include <bitset>
#include <cstdint>

#if defined(__BIT_MANIPULATION_PRACTICE__)
int main() {

	constexpr std::uint8_t option_viewed{ 0x01 };
	//constexpr std::uint8_t option_edited{ 0x02 };
	constexpr std::uint8_t option_favorited{ 0x04 };
	//constexpr std::uint8_t option_shared{ 0x08 };
	constexpr std::uint8_t option_deleted{ 0x10 };

	std::uint8_t myArticleFlags{ option_favorited };

	//goal: using bit manipulation, change the value of
	// myArticleFlags to option_favorited and option_viewed
	// The result should be 0000'0101

	/*
		option_favorited is hex 0x04 represented as an 8 bit number

		The byte representation of this is 0000 0100

		We can use option_viewed as a bit mask and use the bitwise OR
		operator to flip the bit to on
	*/

	myArticleFlags |= option_viewed;

	std::cout << std::bitset<8>{myArticleFlags} << '\n';

	// goal: use one line to determine if the artice was deleted

	std::cout << "The article was" << ((myArticleFlags & option_deleted) ? "" : " not ") << "deleted\n";

	// goal: use one line to clear the article as a favorite
	// expected output: 0000'0001

	myArticleFlags &= ~option_favorited;

	std::cout << std::bitset<8>{myArticleFlags} << "\n";

	return 0;
}
#endif