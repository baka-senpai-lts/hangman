#include "Artwork.hpp"

std::string Artwork::getArt(size_t n) {
	return std::string(this -> ARTS[n]);
}
