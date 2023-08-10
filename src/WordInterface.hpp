#include <iostream>
#include <cctype>

#include "Word.hpp"
#include "Artwork.hpp"
#include "CharAlreadyGuessedException.hpp"

class WordInterface {
	private:
		Artwork* artwork;

		void clearScreen();
		void showAttempts(Word*);
		void showGuessed(Word*);
		void showWord(Word*);
		void showAlphabet(Word*);
		void enterChar(Word*);
		void showWin(Word*);
		void showLose(Word*);

		void showException(CharAlreadyGuessedException);

	public:
		WordInterface();
		~WordInterface();

		// Shows everything in game and lets user to enter next char
		void show(Word*);

		// Shows win or lose depending on the state
		void end(Word*);
};
