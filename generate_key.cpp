#include "generate_key.h"

/**
 * Convert a number in decimal system to hexadecimal system
 *
 * @param dec the input, as an int in decimal number system
 * @returns the equivalent character, in the hexadecimal number system
 */
char dec_to_hex(int dec)
{
	if(dec < 10) {
		return char(48 + dec);
	}
	else {
		return char(65 + dec - 10);
	}
}

/**
 * Generate a random kay of required key length
 *
 * @param key_length the length of the key in bits, as an int 
 * @returns random key, as a string in hexadecimal number system
 */
string generate_key(int key_length)
{
	string key = "";
	for(int i = 0; i < key_length / 4 ; i++) {
		key += dec_to_hex(rand() % 16);
	}
	return key;
}