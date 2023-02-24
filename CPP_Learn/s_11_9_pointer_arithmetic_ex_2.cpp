#include "defineMain.h"

/*
 * LearnCPP Chapter 11 section 8 pointer arithmetic and array indexing
 *
 * Example 2 - std::count_if
 *
 */

#ifdef __S11_8_String_View_EX2__

bool isVowel(char ch)
{
    switch (ch)
    {
    case 'A':
    case 'a':
    case 'E':
    case 'e':
    case 'I':
    case 'i':
    case 'O':
    case 'o':
    case 'U':
    case 'u':
        return true;
    default:
        return false;
    }
}

int main()
{
    return 0;
}

#endif
