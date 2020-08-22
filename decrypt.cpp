#include "decrypt.h"
#include "exor.h"
#include "bin_to_hex.h"
#include "inverse_s_box_substitution.h"
#include "inverse_shift_rows.h"
#include "inverse_mix_columns.h"

/**
 * Decrypt a given ciphertext and obtain the corresponding plaintext
 *
 * @param ciphertext the ciphertext, as a string in hexadecimal number system
 * @param round_keys the references to the 11 round keys 
 * @returns the plaintext, as a string in hexadecimal number system
 */
string decrypt(string ciphertext, string* round_keys)
{
    // round 10
    string intermediate = exor(ciphertext, *(round_keys + 10));
    intermediate = bin_to_hex(intermediate);
    cout << "round 10 : " << intermediate << endl;
    
    // rounds 9 to 1
    for(int i = 9; i > 0; i--) {
        intermediate = inverse_s_box_substitution(intermediate); 
        cout << "round "<<i<<" :  " << intermediate << endl;
        intermediate = inverse_shift_rows(intermediate);
        cout << "           " << intermediate << endl;
        intermediate = inverse_mix_columns(intermediate);
        cout << "           " << intermediate << endl;
        string round_key = *(round_keys + i);
        round_key = inverse_mix_columns(round_key);
        intermediate = exor(intermediate, round_key);
        intermediate = bin_to_hex(intermediate);   
        cout << "           " << intermediate << endl;
    }

    // round 0
    intermediate = inverse_s_box_substitution(intermediate); 
    cout << "round 0 :  " << intermediate << endl;
    intermediate = inverse_shift_rows(intermediate);
    cout << "           " << intermediate << endl;
    string round_key = *(round_keys);
    intermediate = exor(intermediate, round_key);
    string output = bin_to_hex(intermediate);   
    cout << "           " << output << endl;

    return output;  
}