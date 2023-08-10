#include "WordInterface.hpp"


WordInterface::WordInterface() {
	this -> artwork = new Artwork();
}


WordInterface::~WordInterface() {
	delete this -> artwork;
}


void WordInterface::clearScreen() {
	std::cout << "\033[2J\033[1;1H";
}


void WordInterface::showAttempts(Word* word) {
	std::cout << word -> getAttempts() << " attempts left" << std::endl;

	std::cout << this -> artwork -> getArt(word -> getAttempts());
}


void WordInterface::showGuessed(Word* word) {
	std::cout << word -> getGuessedChars() << std::endl;
}


void WordInterface::showWord(Word* word) {
	std::cout << "The word was \"" << word -> getWord() << "\"" << std::endl;
}


void WordInterface::showAlphabet(Word* word) {
	int lineLength = 0;

	for(char& ch : word -> getUnusedChars()) {
		if(lineLength > 10) {
			std::cout << std::endl;
			lineLength = 0;
		}

		std::cout << " " << ch;

		lineLength++;
	}

	std::cout << std::endl;
}


void WordInterface::enterChar(Word* word) {
	char ch;

	std::cout << "Choose your char: ";
	std::cin >> ch;

	if(isalpha(ch)) {
		ch = tolower(ch);
	}

	try {
		word -> guessChar(ch);
	} catch(CharAlreadyGuessedException e) {
		throw e;
	}
}


void WordInterface::showWin(Word* word) {
	std::cout << "Congratulations!" << std::endl;
}


void WordInterface::showLose(Word* word) {
	this -> showWord(word);
	std::cout << "You lost, awful to be you" << std::endl;
}


void WordInterface::showException(CharAlreadyGuessedException e) {
	std::cout << e.what() << std::endl;
}


void WordInterface::show(Word* word) {
	this -> clearScreen();

	this -> showAttempts(word);
	std::cout << "\n";
	this -> showAlphabet(word);
	std::cout << "\n";
	this -> showGuessed(word);
	try {
		this -> enterChar(word);
	} catch(CharAlreadyGuessedException e) {
		this -> showException(e);
	}
}


void WordInterface::end(Word* word) {
	this -> clearScreen();

	this -> showAttempts(word);
	std::cout << "\n";
	this -> showAlphabet(word);
	std::cout << "\n";
	this -> showGuessed(word);
	
	if(word -> won()) {
		this -> showWin(word);
	} else {
		this -> showLose(word);
	}
}
