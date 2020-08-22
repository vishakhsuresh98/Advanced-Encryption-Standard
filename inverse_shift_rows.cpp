#include "inverse_shift_rows.h"
#include "rotate_word.h"

/**
 * Perform InverseShiftRows operation for AES-128 decryption
 *
 * @param input the input string, in hexadecimal number system
 * @returns the output after inverse row shifting, as a string in hexadecimal number system
 */
string inverse_shift_rows(string input)
{
    string output = "";

    // extract rows
    string r0 = input.substr(0, 8);
    string r1 = input.substr(8, 8);
    string r2 = input.substr(16, 8);
    string r3 = input.substr(24, 8);

    // rotate ri, 4 - i times for i != 0
    r1 = rotate_word(r1);
    r1 = rotate_word(r1);
    r1 = rotate_word(r1);
    r2 = rotate_word(r2);
    r2 = rotate_word(r2);
    r3 = rotate_word(r3);

    output = r0 + r1 + r2 + r3;
    return output;
}