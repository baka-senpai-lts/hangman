#include <string>

#pragma once

class Artwork {
	private:
		static constexpr char ARTS[][50] = {
			" ___\n"
			"|   |\n"
			"|   O\n"
			"|  /|\\\n"
			"|  / \\\n",

			" ___\n"
			"|   |\n"
			"|   O\n"
			"|  /|\\\n"
			"|  /\n",

			" ___\n"
			"|   |\n"
			"|   O\n"
			"|  /|\\\n"
			"|\n",

			" ___\n"
			"|   |\n"
			"|   O\n"
			"|  /|\n"
			"|\n",

			" ___\n"
			"|   |\n"
			"|   O\n"
			"|   |\n"
			"|\n",

			" ___\n"
			"|   |\n"
			"|   O\n"
			"|\n"
			"|\n",

			" ___\n"
			"|   |\n"
			"|\n"
			"|\n"
			"|\n",



		};

	public:
		Artwork(){}
		~Artwork(){}

		std::string getArt(size_t n);
};
