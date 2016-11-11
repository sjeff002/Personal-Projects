#include "hangman.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

HangMan::HangMan()
{
	bodyCount = 0;
}

string HangMan::randWord()
{
	string challengeWord;
	unsigned seed;
	seed = time(0);
	srand(seed);
	int randNum = rand() % 40;
	challengeWord = words[randNum];
	return challengeWord;
}

void HangMan::play()
{
	string name;
	string challenge = randWord();
	State status;

	cout << "Let's play HangMan! Before we get started, whatis your name?" << endl;
	cin >> name;
	cout << "Here is the starting game board." << endl;
	for (int i = 0; i < challenge.length(); i++)
		answer.push_back('_');
	printState();

	do {
		cout << "\nThese leters have been guessed:";
		for (int i = 0; i < lettersGuessed.size(); i++)
			cout << lettersGuessed[i] << " ";
		playerGuess(challenge);
		printState();
		status = checkStatus(challenge);
	} while (status == UNFINISHED);
	if (status == WON)
		cout << "\nCongratulations " << name << " you won!" << endl;
	else
		cout << "\nSorry " << name << " you lost." << endl;
}

void HangMan::playerGuess(string a)
{
	char guess;
	bool contains = false;
	
	cout << "\nGuess a letter:" << endl;
	cin >> guess;

	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == guess)
		{
			answer[i] = tolower(guess);
			contains = true;
		}
	}

	if (contains)
		cout << "THat letter is in the word." << endl;
	else
	{
		cout << "That letter is not in the word." << endl;
		bodyCount++;
	}
	lettersGuessed.push_back(guess);
}

void HangMan::printState()
{
	cout << "The body part count is at " << bodyCount << " of 6." << endl;
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << " ";
}

State HangMan::checkStatus(string a)
{
	State status;
	bool same = true;
	bool count = false;

	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] != answer[i])
			same = false;
	}
	if (bodyCount == 6)
		count = true;

	if (count && !same)
		status = LOST;
	else if (same && !count)
		status = WON;
	else
		status = UNFINISHED;
	return status;
}