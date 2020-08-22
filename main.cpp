#include<time.h>

#include "encrypt.h"
#include "decrypt.h"
#include "generate_key.h"
#include "get_round_keys.h"

// Driver program to test the above functions 
int main() 
{  
    srand(time(NULL));
    ifstream in_ptr;
    ofstream out_ptr;

    cout << "Advanced Encryption Standard" << endl;
    cout << "----------------------------\n\n" << endl;

    // encryption process
    cout << "Encryption process :\n" << endl;
    string plaintext; // 128 bits (16 bytes)
    in_ptr.open("plaintext.txt"); 
    getline(in_ptr, plaintext);
    cout << "Plaintext - " << plaintext << endl;
    int key_length = 128; // 128 bits
    string key = generate_key(key_length);
    // string key = "0F470CAF15D9B77F71E8AD67C959D698"; // sample from lecture slides
    cout << "Key - " << key << endl;
    string* round_keys = get_round_keys(key);
    
    string ciphertext = encrypt(plaintext, round_keys); 
    cout << "Ciphertext - " << ciphertext << endl; 
    cout << "\n\n";
    in_ptr.close();

    // decryption process
    cout << "Decryption process :\n" << endl;     
    cout << "Ciphertext - " << ciphertext << endl; 
    cout << "Key - " << key << endl;
    plaintext = decrypt(ciphertext, round_keys); 
    cout << "Plaintext - " << plaintext << endl; 
    cout << "\n\n";

    return 0; 
} 
