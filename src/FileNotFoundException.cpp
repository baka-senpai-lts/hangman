#include "FileNotFoundException.hpp"

char* FileNotFoundException::what() {
	return this -> message;
}
