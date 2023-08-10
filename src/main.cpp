#include <iostream>

#include "WordLoader.hpp"
#include "WordInterface.hpp"
#include "Word.hpp"

int main(int argc, char* argv[]) {
	WordLoader* wordManager = new WordLoader();

	if(argc > 1) {
		try {
			wordManager -> loadWords(argv[1]);
		} catch(IllegalWordException e) {
			std::cerr << e.what() << std::endl;
			return 0;

		} catch(FileNotFoundException e) {
			std::cerr << e.what() << std::endl;
			return 0;
		}
	} else {
		std::cerr << "No file specified" << std::endl;
		return 0;
	}

	Word* word = new Word(wordManager -> getRandomWord(), '_', 6);
	WordInterface* wordInterface = new WordInterface();

	while(!word -> isFinished() && word -> getAttempts() != 0) {
		wordInterface -> show(word);
	}

	wordInterface -> end(word);

	delete wordManager;
	delete word;
	delete wordInterface;

	return 0;
}
