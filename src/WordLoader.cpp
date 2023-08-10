#include "WordLoader.hpp"

// For some reason it doesn't work if use -Wwrite-strings as a compiler argument
#pragma GCC diagnostic ignored "-Wwrite-strings"


bool WordLoader::isCharIllegal(char ch) {
	size_t size = sizeof(this -> ILLEGAL_CHARS);

	for(size_t i = 0; i < size; i++) {
		if((this -> ILLEGAL_CHARS)[i] == ch) {
			return true;
		}
	}
	return false;
}


std::vector<std::string> WordLoader::getWords() {
	return this -> wordlist;
}


void WordLoader::loadWords(std::string filename) {
	std::ifstream file;
	std::string line;

	file.open(filename);

	if(!file) {
		throw FileNotFoundException("Could not open a file");
	}

	while(getline(file, line)) {
		this -> loadWord(line);
	}
}


void WordLoader::loadWord(std::string word) {
	std::transform(word.begin(), word.end(), word.begin(), tolower);

	if(!(this -> validateWord(word))) {
		throw IllegalWordException("Word contains illegal characters");
	}

	(this -> wordlist).push_back(word);
}


bool WordLoader::validateWord(std::string word) {
	for(int i = 0; i < word.length(); i++) {
		if(this -> isCharIllegal(word[i])) {
			return false;
		}
	}

	return true;
}


std::string WordLoader::getRandomWord() {
	srand(time(NULL));

	return this -> wordlist[rand() % this -> wordlist.size()];
}
