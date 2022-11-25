
#include <iostream>
#include <sstream>
#include <cstring>
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
	#include <io.h>
#else
	#include <unistd.h>
#endif
#include <stdio.h>

enum action_t : char {
	CIPHER = 'c',
	DECIPHER = 'd'
};

/**
 * @brief true if stdin is terminal input, false if stdin is a pipe
 */
inline bool isNotPipe() {
	return isatty(fileno(stdin));
}

/**
 * @brief true if stdout is the terminal, false if stdout is a pipe
 */
inline bool isNotPipeOut() {
	return isatty(fileno(stdout));
}

std::string caesar(int8_t shift, std::string stream);

/**
 * @brief Something went wrong! Exit out of Europe like the British did
 */
inline void brexit(const char *what);

int main(int argc, char **argv) {
	for(int i = 1; i < argc; i++) {
		if(!strcmp(argv[i], "-h") || !strcmp(argv[i], "--help")) {
			std::cout << "\nINFO:\n\tUSAGE:\t" << argv[0] << " [c(ipher)|d(ecipher)] [shift (1-25)] [\"text here\"]\n" << std::endl;
			return 255;
		}
	}

	char action;
	int16_t shift;
	std::string text;

	try {
		bool nPipe = isNotPipe();
		
		if(argc > 1) {
			action = argv[1][0];
		} else {
			if(nPipe) {
				std::cout << "Enter action: (c - cipher, d - decipher) ";
				std::cout.flush();
			}
			std::cin >> action;
		}

		if(action != CIPHER && action != DECIPHER)
			throw std::runtime_error("Action parameter can only be c(ipher) or d(ecipher)");
		
		
		if(argc > 2) {
			shift = std::stoi(argv[2]);
		} else {
			if(nPipe) {
				std::cout << "Enter shift: (1-25) ";
				std::cout.flush();
			}
			std::cin >> shift;
		}

		if(shift < 1)
			throw std::runtime_error("Shift cannot be less than 1");

		if(shift > 25)
			throw std::runtime_error("Shift cannot be more than 25");
		
		if(argc > 3) {
			text = argv[3];
		} else {
			if(nPipe) {
				std::cout << "Text to " << (action == CIPHER ? "" : "de") << "cipher: ";
				std::cout.flush();

				std::cin >> text;
			} else {
				std::stringstream stream;
				stream << std::cin.rdbuf();
				text = stream.str();
			}
		}

		std::cout << caesar(shift * (action == CIPHER ? 1 : -1), text);

		if(isNotPipeOut())
			std::cout << std::endl;
		else
			std::cout.flush();
	} catch(const std::exception &ex) {
		brexit(ex.what());
	}
}

inline void brexit(const char *what) {
	std::cerr << "BREXIT: " << what << std::endl;
	exit(1);
}

char charCaesar(char firstChar, char i, int shift) {
	int index = i - firstChar;
	index += shift;

	if(shift < 0 && index < 0)
		index = 26 + index;
	else
		index %= 25;

	return firstChar + index;
}

std::string caesar(int8_t shift, std::string stream) {
	std::string out = std::string();

	char res;
	for(auto &i : stream) {
		if(i >= 'A' && i <= 'Z')
			res = charCaesar('A', i, shift);
		else if(i >= 'a' && i <= 'z')
			res = charCaesar('a', i, shift);
		else
			res = i;

		out += res;
	}

	return out;
}
