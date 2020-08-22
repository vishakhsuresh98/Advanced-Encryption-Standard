#include "rotate_word.h"

/**
 * Rotate 4 byte word by 1 byte to the left
 *
 * @param input the input string, in hexadecimal number system
 * @returns the output after left shifting the word, as a string in hexadecimal number system
 */
string rotate_word(string input) 
{
    // to transform any input of form "ab cd ef gh" to "cd ef gh ab"
    string output = input.substr(2, 6) + input.substr(0, 2);
    return output;
}