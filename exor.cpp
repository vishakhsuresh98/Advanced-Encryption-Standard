#include "exor.h"
#include "hex_to_bin.h"

/**
 * Compute the exclusive or of 2 strings provided as input
 *
 * @param input_1 the first input, as a string in hexadecimal number system
 * @param input_2 the second input, as a string in hexadecimal number system
 * @returns the XOR of the inputs, as a string in binary number system
 */
string exor(string input_1, string input_2)
{
    // convert inputs to binary
    input_1 = hex_to_bin(input_1);
    input_2 = hex_to_bin(input_2);
    string output = "";
    for(int i = 0; i < input_1.size(); i++) {
        if(input_1[i] == input_2[i]) {
            output += '0';
        }
        else {
            output += '1';
        }
    }
    return output;
}