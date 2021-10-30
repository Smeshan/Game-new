#ifndef KEYWORDS_H
#define KEYWORDS_H
/* C system icnludes */

/* C++ system icnludes */
#include <array>

/* Third-party icnludes */

/* Own icnludes */

/* Forward Declaration */

constexpr auto KEYWORDS_COUNT = 5;

const std::array<std::string, KEYWORDS_COUNT> KEY_WORDS{
 "if",
 "else",
 "bool",
 "true",
 "false"
};

class KeyWords {

public:
	KeyWords() = delete;
	~KeyWords();

	static bool checkForKeyWord(const std::string& word);

};
#endif