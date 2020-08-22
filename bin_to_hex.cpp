#include "bin_to_hex.h"

/**
 * Convert a number in binary system to hexadecimal system
 *
 * @param bin the input string, in binary number system
 * @returns the equivalent string, in the hexadecimal number system
 */
string bin_to_hex(string bin)
{
	unordered_map <string, string> mp; 
    mp["0000"] = "0"; 
    mp["0001"] = "1"; 
    mp["0010"] = "2"; 
    mp["0011"] = "3"; 
    mp["0100"] = "4"; 
    mp["0101"] = "5"; 
    mp["0110"] = "6"; 
    mp["0111"] = "7"; 
    mp["1000"] = "8"; 
    mp["1001"] = "9"; 
    mp["1010"] = "A"; 
    mp["1011"] = "B"; 
    mp["1100"] = "C"; 
    mp["1101"] = "D"; 
    mp["1110"] = "E"; 
    mp["1111"] = "F";

    string hex = ""; 
    for (int i = 0; i < bin.length(); i += 4) { 
        string ch = ""; 
        ch += bin[i]; 
        ch += bin[i + 1]; 
        ch += bin[i + 2]; 
        ch += bin[i + 3]; 
        hex += mp[ch]; 
    } 
    return hex;
}