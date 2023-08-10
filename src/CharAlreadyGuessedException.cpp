#include "CharAlreadyGuessedException.hpp"

char* CharAlreadyGuessedException::what() {
	return this -> message;
}
