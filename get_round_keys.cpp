#include "get_round_keys.h"
#include "key_expansion.h"

/**
 * Getter function to compute and return the round keys (11 in number, each of 16 bytes)
 *
 * @param key the key, as a string in hexadecimal number system
 * @returns the round keys, as strings in hexadecimal number system
 */
string* get_round_keys(string key)
{
    static string round_keys[11] = {};
    string* key_expanded = key_expansion(key);

    for(int i = 0; i <= 10; i++) {
        string round_key = "";
        string w0 = *(key_expanded + 4 * i);
        string w1 = *(key_expanded + 4 * i + 1);
        string w2 = *(key_expanded + 4 * i + 2);
        string w3 = *(key_expanded + 4 * i + 3);
        for(int j = 0; j < 4; j++) {
            round_key += w0.substr(j * 2, 2);
            round_key += w1.substr(j * 2, 2);
            round_key += w2.substr(j * 2, 2);
            round_key += w3.substr(j * 2, 2);
        }
        round_keys[i] = round_key;
    }
    return round_keys;
}