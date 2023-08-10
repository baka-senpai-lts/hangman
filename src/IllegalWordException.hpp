#include <exception>

#pragma once

class IllegalWordException : public std::exception {
	private:
		char* message;

	public:
		IllegalWordException(char* msg) : message(msg) {}
		char* what();
};
