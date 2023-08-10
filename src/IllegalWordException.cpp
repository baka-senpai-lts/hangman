#include "IllegalWordException.hpp"

char* IllegalWordException::what() {
	return this -> message;
}
