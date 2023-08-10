#include <exception>

#pragma once

class CharAlreadyGuessedException : public std::exception {
	private:
		char* message;

	public:
		CharAlreadyGuessedException(char* msg) : message(msg) {}
		char* what();
};
