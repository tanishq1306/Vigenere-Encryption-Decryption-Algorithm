//This file contains definition of all the member function declared inside Vigenere.h
#include "Vigenere.h"

Vigenere::Vigenere() {
	key = "DEFAULTKEY";
}

Vigenere::Vigenere(string &key) {
	 assert(key.size() > 0);
	 setKey(key);
}

void Vigenere::setKey(string &key) {
	assert(key.size() > 0);
	this -> key = key;
}

string Vigenere::getKey() {
	return key;
}

string Vigenere::toUpperCase(string &key) {
	assert(key.size() > 0);
	string upperCaseKey = key;
	for (char &ch: upperCaseKey) {
		if(ch >= 'a' and ch <= 'z') {
			ch -= 32;
		}
	}
	
	return upperCaseKey;
}

string Vigenere::encrypt(string &word) {
	assert(key.size() > 0);
	string output;
	for (int i = 0, j = 0; i < (int)word.length(); ++i) {
		char c = word[i];
		if (c >= 'a' && c <= 'z') {
			c += 'A' - 'a';
		}
		else if (c < 'A' || c > 'Z') {
			continue;
		}
		
		//added 'A' to bring it in range of ASCII alphabet [ 65-90 | A-Z ]
		output += (c + key[j] - 2 * 'A') % 26 + 'A'; 
		j = (j + 1) % key.length();
	}
	
	return output; 
}

string Vigenere::decrypt(string &word) {
	assert(key.size() > 0);
	string output;
	for (int i = 0, j = 0; i < (int)word.length(); ++i) {
		char c = word[i];
		if (c >= 'a' && c <= 'z') {
			c += 'A' - 'a';
		}
		else if (c < 'A' || c > 'Z') {
			continue;
		}
		
		//added 'A' to bring it in range of ASCII alphabet [ 65-90 | A-Z ]
		output += (c - key[j] + 26) % 26 + 'A';
		j = (j + 1) % key.length();
	}
	
	return output; 
}
