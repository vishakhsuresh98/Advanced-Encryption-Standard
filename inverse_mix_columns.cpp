#include "inverse_mix_columns.h"
#include "exor.h"
#include "gallois_field_and.h"
#include "bin_to_hex.h"

/**
 * Perform InverseMixColumns operation for AES-128 decryption
 *
 * @param input the input string, in hexadecimal number system
 * @returns the output after InverseMixColumns, as a string in hexadecimal number system
 */
string inverse_mix_columns(string input) 
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
        string s0_9 = gallois_field_and(s0, 9);
        string s0_11 = gallois_field_and(s0, 11);
        string s0_13 = gallois_field_and(s0, 13);
        string s0_14 = gallois_field_and(s0, 14);

        string s1_9 = gallois_field_and(s1, 9);
        string s1_11 = gallois_field_and(s1, 11);
        string s1_13 = gallois_field_and(s1, 13);
        string s1_14 = gallois_field_and(s1, 14);

        string s2_9 = gallois_field_and(s2, 9);
        string s2_11 = gallois_field_and(s2, 11);
        string s2_13 = gallois_field_and(s2, 13);
        string s2_14 = gallois_field_and(s2, 14);

        string s3_9 = gallois_field_and(s3, 9);
        string s3_11 = gallois_field_and(s3, 11);
        string s3_13 = gallois_field_and(s3, 13);
        string s3_14 = gallois_field_and(s3, 14);

        output_0 += bin_to_hex(exor(bin_to_hex(exor(bin_to_hex(exor(s0_14, s1_11)), s2_13)), s3_9));
        output_1 += bin_to_hex(exor(bin_to_hex(exor(bin_to_hex(exor(s0_9, s1_14)), s2_11)), s3_13));
        output_2 += bin_to_hex(exor(bin_to_hex(exor(bin_to_hex(exor(s0_13, s1_9)), s2_14)), s3_11));
        output_3 += bin_to_hex(exor(bin_to_hex(exor(bin_to_hex(exor(s0_11, s1_13)), s2_9)), s3_14));
    }

    string output = output_0 + output_1 + output_2 + output_3;
    return output;
}