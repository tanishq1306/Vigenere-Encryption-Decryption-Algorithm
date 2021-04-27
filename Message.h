#ifndef MESSAGE_H
#define MESSAGE_H
#include "Vigenere.cpp"

/* Message class contains a vector of strings that holds words that were 
   either encrypted or decrypted & functions to encrypt & decrypt a word.
*/
class Message {
		vector<string> words;
		Vigenere v;
		
	public:
		/* 	parameterized constructor with key as parameter converts the key to uppercase and
			calls Vigenere constructor to set the key value
		*/ 
		Message(string &key);	
		
		/* This fuction converts the *token to string and calls the encrypt fn of class Vigenere 
		   gets the encrypted word and pushes it into the words vector
		*/
		void encryptWord(char* token);
		
		/* This fuction converts the *token to string and calls the decrypt fn of class Vigenere 
		   gets the decrypted word and pushes it into the words vector
		*/ 
		void decryptWord(char* token);
		
		/* This fuction takes fileName as parameter and creates a fileName.txt
		   with decrypted content
		*/
		void makeFile(string &fileName);
		
		// This fuction shows the words stored in words vector
		void showWords();
}; 

#endif
