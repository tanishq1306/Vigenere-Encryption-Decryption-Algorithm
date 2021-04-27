#include "Message.cpp"
#define FILE_SIZE 1000

/** Utility Functions**/
void displayMenu();
void encrypt(string &key);
void decrypt(string &key);

int main() {
	
	while (true) {
		displayMenu();	
	}

	return 0;
}

void displayMenu() {
	system("cls");
	string key;
	cout << "Enter an encryption / decryption KEY: ";
	getline(cin, key);
	
	if (key.size() == 0) {
		getline(cin, key);
	}
	 
	int choice;
	cout << "\n\tVigenere Cypher";
	cout << "\n\t---------------";
	cout << "\n\nMain Menu";
	cout << "\n\n1 - Encrypt File";
	cout << "\n2 - Decrypt File";
	cout << "\n3 - Quit";
	
	cout << "\n\nSelection: ";
	cin >> choice;
	
	switch(choice) {
		case 1:
			encrypt(key);
			break;
		case 2:
			decrypt(key);
			break;
		case 3:
			exit(0);
		default:
			cout << "\nInvalid Choice\n";
			break;
	}
	
	cout << "\n\n";
	system("pause");

}

void encrypt(string &key) {
	cin.ignore();
	string fileName;
	cout << "Enter the name of the file to encrypt: ";
	getline(cin, fileName);
	
	// check whether file exist or not
	string path = fileName + ".txt";
	ifstream fin(path);
	
	if (fin.fail()) {
		cout << "No File exist with name " << path << "\n";
		return;
	}
	
	// read the file content
	char fileContent[FILE_SIZE];
	fin.read((char *)& fileContent,sizeof(fileContent));
    fin.close();
    
	// display the file content
	for (int i = 0; fileContent[i] != '\0'; i++) {
		cout << fileContent[i];
	}
	
	Message message(key);
	char *next_token = NULL, *token = NULL; 
	char separators[] = " ";
	token = strtok_s(fileContent, separators, &next_token);

	// tokenize the message into separate words
	// while there are tokens in fileContent
	while ((token != NULL)) {
		// get the next token
		// call encryptWord function in message class (using message object)
		// passing each token as argument
		
		// cout << token << "\n";
		message.encryptWord(token);
		token = strtok_s(NULL, separators, &next_token);
	}
	
	cout << "\n\nA new file will be created that contains the encrypted message\n";
	cout << "Please enter the name of the new file to create : ";
	getline(cin, fileName);
	message.makeFile(fileName);
	
	cout << "\n\nThe new file contains the following encrypted message\n\n";
	message.showWords();
}

void decrypt(string &key) {
	cin.ignore();
	string fileName;
	cout << "Enter the name of the file to decrypt: ";
	getline(cin, fileName);
	
	// check whether file exist or not
	string path = fileName;// + ".txt";
	ifstream fin(path);
	
	if (fin.fail()) {
		cout << "No File exist with name " << path << "\n";
		return;
	}
	
	// read the file content
	char fileContent[FILE_SIZE];
	fin.read((char *)& fileContent,sizeof(fileContent));
    fin.close();
    
	// display the file content
	for (int i = 0; fileContent[i] != '\0'; i++) {
		cout << fileContent[i];
	}
	
	Message message(key);
	char *next_token = NULL, *token = NULL; 
	char separators[] = " ";
	token = strtok_s(fileContent, separators, &next_token);

	// tokenize the message into separate words
	// while there are tokens in fileContent
	while ((token != NULL)) {
		// get the next token
		// call encryptWord function in message class (using message object)
		// passing each token as argument
		
		// cout << token << "\n";
		message.decryptWord(token);
		token = strtok_s(NULL, separators, &next_token);
	}
	
	cout << "\n\nThe new file contains the following encrypted message\n\n";
	message.showWords();
}
