#include "key_expansion.h"
#include "rotate_word.h"
#include "s_box_substitution.h"
#include "get_round_constant.h"
#include "exor.h"
#include "bin_to_hex.h"
#include "hex_to_bin.h"

/**
 * Performs key expansion and return the key schedule (44 words)
 *
 * @param key the key, as a string in hexadecimal number system
 * @returns the key schedule (44 words, each of 4 bytes), as strings in hexadecimal number system
 */
string* key_expansion(string key)
{
    static string key_expanded[44] = {};
    
    // first 4 words
    for(int i = 0; i < 4; i++) {
        for(int j = 2 * i; j < 32; j += 8) {
            key_expanded[i] += key.substr(j, 2);
        }
    }
    
    for(int i = 1; i <= 10; i++) {
        // i = round
        string w0 = key_expanded[4 * i - 4];
        string w1 = key_expanded[4 * i - 3];
        string w2 = key_expanded[4 * i - 2];
        string w3 = key_expanded[4 * i - 1];
        string x1 = rotate_word(w3);
        string y1 = s_box_substitution(x1);
        string rcon = get_round_constant(i);
        string z1 = bin_to_hex(exor(y1, rcon));
        
        key_expanded[4 * i] = bin_to_hex(exor(w0, z1));
        key_expanded[4 * i + 1] = bin_to_hex(exor(w1, key_expanded[4 * i]));
        key_expanded[4 * i + 2] = bin_to_hex(exor(w2, key_expanded[4 * i + 1]));
        key_expanded[4 * i + 3] = bin_to_hex(exor(w3, key_expanded[4 * i + 2]));
    }

    return key_expanded;
}