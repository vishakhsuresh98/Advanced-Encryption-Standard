#include "gallois_field_and.h"
#include "exor.h"
#include "hex_to_bin.h"
#include "bin_to_hex.h"

/**
 * Multiply by 0x02 in GF(2^8)
 *
 * @param input the number to be multiplied, as a string in hexadecimal number system
 * @returns the result after multiplying by 0x02, as a string in hexadecimal number system
 */
string gf_multiply_two(string input) 
{
    /** 
     * Multiplying by 2 is equivelent to :
     * shifting the number left by one, 
     * and then XORing the value 0x1B if the high bit had been one. 
     * If the high bit was a zero, 
     * then you dont need to XOR anything. 
     */
    string output = "";
    input = hex_to_bin(input);
    char high_bit = input.at(0);

    // shift left by 1
    input = input + '0';
    input = input.substr(1, input.size());
    if(high_bit == '0') {
        output = bin_to_hex(input);
    }
    else {
        output = bin_to_hex(exor(bin_to_hex(input), "1B"));
    }
    return output;
}

/**
 * Perform multiplication with an input muliplier, in GF(2^8)
 *
 * @param input the number to be multiplied, as a string in hexadecimal number system
 * @param multiplier the number with which input is to be multiplied, as a int in decimal number system
 * @returns the result after multiplying, as a string in hexadecimal number system
 */
string gallois_field_and(string input, int multiplier)
{
    // accepts input in hexa format and outputs in 
    string output = "";
    if(multiplier == 1) {
        output = input;
    }
    else if(multiplier == 2) {
        output = gf_multiply_two(input);     
    }
    else if(multiplier == 3) {
        /**
         * Multiplying by 3 is equivelent to :
         * multiplying by 𝟸 (in gallois field), and then XORing that with the original value, 
         * since  x * 3 = (x * 2) + 3 
         */
        output = bin_to_hex(exor(gf_multiply_two(input), input));
    }
    else if (multiplier == 9) {
        /** 
         * Multiplying by 9 logic : 
         * x * 9 = (((x * 2) * 2) * 2) + x 
         */
        output = bin_to_hex(exor(gf_multiply_two(gf_multiply_two(gf_multiply_two(input))), input));    
    }
    else if (multiplier == 11) {
        /**
         * Multiplying by 11 logic :
         * x * 11 = ((((x * 2) * 2) + x) * 2) + x 
         */
        output = bin_to_hex(exor(gf_multiply_two(bin_to_hex(exor(gf_multiply_two(gf_multiply_two(input)), input))), input));
    }
    else if (multiplier == 13) {
        /**
         * Multiplying by 13 logic :
         * x * 13 = ((((x * 2) + x) * 2) * 2) + x 
         */
        output = bin_to_hex(exor(gf_multiply_two(gf_multiply_two(bin_to_hex(exor(gf_multiply_two(input), input)))), input));
    }
    else if (multiplier == 14) {
        /**
         * Multiplying by 13 logic :
         * x * 14 = ((((x * 2) + x) * 2) + x) * 2
         */
        output = gf_multiply_two(bin_to_hex(exor(gf_multiply_two(bin_to_hex(exor(gf_multiply_two(input), input))), input)));
    }
    return output;
}