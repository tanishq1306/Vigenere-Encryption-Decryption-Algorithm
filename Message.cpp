//This file contains definition of all the member function declared in Message.h
#include "Message.h"

Message::Message(string &key) {
	assert(key.size() > 0);
	key = v.toUpperCase(key);
	v.setKey(key);
}

void Message::encryptWord(char* token) {
	assert(token != NULL);
	string word;
	for (int indx = 0;  token[indx] != '\0'; indx++) {
		word += token[indx];
	}

	word = v.toUpperCase(word);
	string encryptedWord = v.encrypt(word);
	words.push_back(encryptedWord);
}

void Message::decryptWord(char* token) {
	assert(token != NULL);
	string word;
	for (int indx = 0;  token[indx] != '\0'; indx++) {
		word += token[indx];
	}
	
	string decryptedWord = v.decrypt(word);
	words.push_back(decryptedWord);
}

void Message::makeFile(string &fileName) {
	assert(fileName.size() > 0);
	fstream fout;
	fout.open(fileName, ios::out);
	
	// If no file is created, then	
	// show the error message.
	if (!fout) {
	   cout << "Error in creating file!!!";
	   exit(1);
	}
   
    for (string word: words) {
		fout << word;
		fout << " ";
	}
	
	fout.close();
}

void Message::showWords() {
	for (string word: words) {
		cout << word << " ";
	}
}
