#include <exception>

#pragma once

class FileNotFoundException : public std::exception {
	private:
		char* message;

	public:
		FileNotFoundException(char* msg) : message(msg) {}
		char* what();
};
