#include "encrypt.h"
#include "exor.h"
#include "bin_to_hex.h"
#include "s_box_substitution.h"
#include "shift_rows.h"
#include "mix_columns.h"

/**
 * Encrypt a given plaintext and obtain the corresponding ciphertext
 *
 * @param plaintext the plaintext, as a string in hexadecimal number system
 * @param round_keys the references to the 11 round keys 
 * @returns the ciphertext, as a string in hexadecimal number system
 */
string encrypt(string plaintext, string* round_keys)
{
    // round 0
    string intermediate = exor(plaintext, *(round_keys));
    intermediate = bin_to_hex(intermediate);
    cout << "round 0 :  " << intermediate << endl;

    // rounds 1 to 9
    for(int i = 1; i <= 9; i++) {
        string round_key = *(round_keys + i);
        intermediate = s_box_substitution(intermediate);
        cout << "round "<<i<<" :  " << intermediate << endl;
        intermediate = shift_rows(intermediate);
        cout << "           " << intermediate << endl;
        intermediate = mix_columns(intermediate);
        cout << "           " << intermediate << endl;
        intermediate = exor(intermediate, round_key);
        intermediate = bin_to_hex(intermediate);
        cout << "           " << intermediate << endl;
    }

    // round 10
    intermediate = s_box_substitution(intermediate);
    cout << "round 10 : " << intermediate << endl;
    intermediate = shift_rows(intermediate);
    cout << "           " << intermediate << endl;
    intermediate = exor(intermediate, *(round_keys + 10));
    string output = bin_to_hex(intermediate);
    cout << "           " << output << endl;

    return output;
}