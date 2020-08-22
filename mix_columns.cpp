#include "mix_columns.h"
#include "exor.h"
#include "gallois_field_and.h"
#include "bin_to_hex.h"

/**
 * Perform MixColumns operation for AES-128 encryption
 *
 * @param input the input string, in hexadecimal number system
 * @returns the output after MixColumns, as a string in hexadecimal number system
 */
string mix_columns(string input) 
{
    string output_0 = "";
    string output_1 = "";
    string output_2 = "";
    string output_3 = "";

    for(int i = 0; i < 4; i++) {    
        string s0 = input.substr(0 + i * 2, 2);
        string s1 = input.substr(8 + i * 2, 2);
        string s2 = input.substr(16 + i * 2, 2);
        string s3 = input.substr(24 + i * 2, 2);
        
        // results of multiplication in GF(2^8)
        string s0_2 = gallois_field_and(s0, 2);
        string s0_3 = gallois_field_and(s0, 3);
        string s1_2 = gallois_field_and(s1, 2);
        string s1_3 = gallois_field_and(s1, 3);
        string s2_2 = gallois_field_and(s2, 2);
        string s2_3 = gallois_field_and(s2, 3);
        string s3_2 = gallois_field_and(s3, 2);
        string s3_3 = gallois_field_and(s3, 3);

        output_0 += bin_to_hex(exor(bin_to_hex(exor(bin_to_hex(exor(s0_2, s1_3)), s2)), s3));
        output_1 += bin_to_hex(exor(bin_to_hex(exor(bin_to_hex(exor(s0, s1_2)), s2_3)), s3)); 
        output_2 += bin_to_hex(exor(bin_to_hex(exor(bin_to_hex(exor(s0, s1)), s2_2)), s3_3));
        output_3 += bin_to_hex(exor(bin_to_hex(exor(bin_to_hex(exor(s0_3, s1)), s2)), s3_2));  
    }

    string output = output_0 + output_1 + output_2 + output_3;
    return output;
}