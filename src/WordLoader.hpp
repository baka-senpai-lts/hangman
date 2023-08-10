#include <string>
#include <string.h>
#include <vector>
#include <fstream>
#include <ctime>
#include <algorithm>
#include <cctype>

#include "FileNotFoundException.hpp"
#include "IllegalWordException.hpp"

#pragma once

class WordLoader {
	private:
		std::vector<std::string> wordlist;
		static constexpr char ILLEGAL_CHARS[] = "1234567890-=!@#$%^&*()_+`~\\|,./<>? ";

		// Check if char is in ILLEGAL_CHARS
		bool isCharIllegal(char);
		// Load single word
		void loadWord(std::string); 

	public:
		WordLoader(){}
		~WordLoader(){}

		// Load words from a file
		void loadWords(std::string);

		// Validates whole word using isCharIllegal
		bool validateWord(std::string); 

		std::vector<std::string> getWords();
		std::string getRandomWord();
};
