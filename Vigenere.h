#ifndef VIGENERE_H
#define VIGENERE_H
#include <bits/stdc++.h>	// includes all generic libraries
using namespace std;

/* Vigenere class contains the encryption key & 
   logic for encrypting & decrypting individual words.
*/  

class Vigenere {
		string key;
		
	public:
		// default constructor sets the key value as "DEFAULT"
		Vigenere();
		
		// parameterized constructor sets the key value equal to key parameter provided by User
		Vigenere(string &key);
		
		// This function sets the key value equal to key parameter provided by User
		void setKey(string &key);
		
		// This function returns key 
		string getKey();
		
		// This function converts whole key to upper-case alphabets
		string toUpperCase(string &key);
		
		// This function encrypts the word and returns the encrypted word
		string encrypt(string &word);
		
		// This function decrypts the word and returns the decrypted word
 		string decrypt(string &word);
}; 

#endif
