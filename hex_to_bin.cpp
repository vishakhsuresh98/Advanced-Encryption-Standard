#include "hex_to_bin.h"

/**
 * Convert a number in hexadecimal system to binary system
 *
 * @param hex the input string, in hexadecimal number system
 * @returns the equivalent string, in the binary number system
 */
string hex_to_bin(string hex)
{
	unordered_map <char, string> mp; 
    mp['0'] = "0000"; 
    mp['1'] = "0001"; 
    mp['2'] = "0010"; 
    mp['3'] = "0011"; 
    mp['4'] = "0100"; 
    mp['5'] = "0101"; 
    mp['6'] = "0110"; 
    mp['7'] = "0111"; 
    mp['8'] = "1000"; 
    mp['9'] = "1001"; 
    mp['A'] = "1010"; 
    mp['B'] = "1011"; 
    mp['C'] = "1100"; 
    mp['D'] = "1101"; 
    mp['E'] = "1110"; 
    mp['F'] = "1111";
     
    string bin = ""; 
    for (int i = 0; i < hex.size(); i++) { 
        bin += mp[hex[i]]; 
    }
    return bin;
}