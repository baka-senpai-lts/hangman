#include "Word.hpp"
 
// For some reason it doesn't work if use -Wwrite-strings as a compiler argument
#pragma GCC diagnostic ignored "-Wwrite-strings"


Word::Word(std::string word, char notGuessedChar, unsigned short int attemptsLeft) {
	this -> notGuessedChar = notGuessedChar;
	this -> attemptsLeft = attemptsLeft;

	this -> usedChars = "";
	this -> unusedChars = "";

	char lwalpCh;

	for(lwalpCh = 97; lwalpCh <= 122; lwalpCh++){
		unusedChars += lwalpCh;
	}

	this -> word = word;
	this -> guessedChars = std::string(word.length(), this -> notGuessedChar);
}


std::vector<int> Word::findLocation(std::string sample, char findIt) {
	std::vector<int> characterLocations;

    for(int i = 0; i < sample.size(); i++) {
        if(sample[i] == findIt) {
            characterLocations.push_back(i);
		}
	}

    return characterLocations;
}


std::string Word::getWord() {
	return this -> word;
}


void Word::updateGuessedChars(char ch) {
	std::vector<int> occurrences = this -> findLocation(this -> word, ch);

	for(auto i : occurrences) {
		this -> guessedChars[i] = this -> word[i];
	}
}


std::string Word::getGuessedChars() {
	return this -> guessedChars;
}


std::string Word::getUnusedChars() {
	return this -> unusedChars;
}


std::string Word::getUsedChars() {
	return this -> usedChars;
}


unsigned short int Word::getAttempts() {
	return this -> attemptsLeft;
}


bool Word::guessChar(char ch) {
	if(this -> usedChars.find(ch) == std::string::npos) {
		this -> usedChars += ch;
	} else {	
		throw CharAlreadyGuessedException("This character was already guessed");
	}

	if(this -> unusedChars.find(ch) != std::string::npos) {
		this -> unusedChars[this -> unusedChars.find(ch)] = this -> notGuessedChar;
	}

	if(this -> word.find(ch) != std::string::npos) {
		if(this -> guessedChars.find(ch) == std::string::npos) {
			this -> updateGuessedChars(ch);
		}

		return true;
	}

	this -> attemptsLeft--;
	return false;
}


bool Word::isFinished() {
	return this -> guessedChars.find(this -> notGuessedChar) == std::string::npos;
}


bool Word::won() {
	return this -> attemptsLeft > 0 && this -> isFinished();
}
