#include <string>
#include <vector>

#include "CharAlreadyGuessedException.hpp"

#pragma once

class Word {
	private:
		char notGuessedChar;
		unsigned short int attemptsLeft;

		std::string word;
		std::string unusedChars;

		// Contains chars already chosen for guess
		std::string usedChars;
		std::string guessedChars;

		std::vector<int> findLocation(std::string, char);
		void updateGuessedChars(char);

	public:
		Word(std::string, char, unsigned short int);
		~Word(){};

		std::string getWord();

		// Returns string that contains guessed characters
		// and space if char is not guessed yet
		std::string getGuessedChars();

		std::string getUnusedChars();
		std::string getUsedChars();

		// Returns remaining attempts (decreases when guess
		// is incorect)
		unsigned short int getAttempts();
		
		// Returns true if there is this char
		bool guessChar(char);

		// Checks if there is no not-guessed chars
		bool isFinished();

		// Checks if player won 
		bool won();
};
