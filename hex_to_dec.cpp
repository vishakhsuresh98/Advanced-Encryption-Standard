#include "hex_to_dec.h"

/**
 * Convert a number in hexadecimal system to decimal system
 *
 * @param hex the input char, in hexadecimal number system
 * @returns the equivalent int, in the decimal number system
 */
int hex_to_dec(char hex)
{
	unordered_map <char, int> mp; 
    mp['0'] = 0; 
    mp['1'] = 1; 
    mp['2'] = 2; 
    mp['3'] = 3; 
    mp['4'] = 4; 
    mp['5'] = 5; 
    mp['6'] = 6; 
    mp['7'] = 7; 
    mp['8'] = 8; 
    mp['9'] = 9; 
    mp['A'] = 10; 
    mp['B'] = 11; 
    mp['C'] = 12; 
    mp['D'] = 13; 
    mp['E'] = 14; 
    mp['F'] = 15;
     
    int dec = mp[hex];
    return dec;
}