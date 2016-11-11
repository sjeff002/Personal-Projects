#ifndef HANGMAN_HPP
#define HANGMAN_HPP
#include <string>
#include <vector>

enum State {WON, LOST, UNFINISHED};

class HangMan
{
private:
	std::string words[40] = { "fox", "man","cat","pun","him", "jazz", "kick", "rake", "time", "nest", "flick",
							"print", "taste", "worry", "color", "string", "insert", "purple", "vacuum", "eraser",
							"stencil", "explore", "mermaid", "sapphire", "pumpkin", "material", "handicap", "analysis",
							"purchase", "sandwich", "raspberry", "jackfruit", "objectify", "machinery", "invisible",
							"instrument", "dictionary", "navigation", "excitement", "mesmerized"};
	int bodyCount;
	std::vector <char> answer;
	std::vector <char> lettersGuessed;
public:
	HangMan();
	std::string randWord();
	void play();
	void playerGuess(std::string);
	void printState();
	State checkStatus(std::string);
};
#endif