#include "get_round_constant.h"

/**
 * Getter function to obtain the Rcon (round constant) for key expansion
 *
 * @param round the round number, as an int 
 * @returns the round constant, as a string in hexadecimal number system
 */
string get_round_constant(int round)
{
    unordered_map <int, string> mp; 
    mp[1] = "01000000"; 
    mp[2] = "02000000"; 
    mp[3] = "04000000"; 
    mp[4] = "08000000"; 
    mp[5] = "10000000"; 
    mp[6] = "20000000"; 
    mp[7] = "40000000"; 
    mp[8] = "80000000"; 
    mp[9] = "1B000000"; 
    mp[10] = "36000000";

    string rcon = mp[round];
    return rcon;
}