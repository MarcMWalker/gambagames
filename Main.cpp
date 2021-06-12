#include <iostream>
#include "User.h"
#include "BlackJack.h"

void printInstructions() {
	std::cout << "Welcome to the 'Gambling room'\n";
	std::cout << "------------------------------------\n";
	std::cout << "(A): Add funds to account\n";
	std::cout << "(B): Play Blackjack\n";
	std::cout << "(C): Change money to chips\n";
	std::cout << "(E): Exit Casino and cash out chips\n";
	std::cout << "------------------------------------\n";
}

void creatBlackJackGame() {
	BlackJack* game = new BlackJack;
	std::cout << "*** Now Playing Blackjack ***\n";
}

char input() {
	char choice{};
	std::cout << "Input>> ";
	std::cin >> choice;
	return choice;
}

void menuChoice(char input, User* user, bool &exit) {
	switch (input) {
	case 'a':
	case 'A':
		user->addFunds();
		break;
	case 'b':
	case 'B':
		//start blackjack game with user
		creatBlackJackGame();
		break;
	case 'c':
	case 'C':
		user->transferFundsToChips();
		break;
	case 'e':
	case 'E':
		exit = true;
		user->transferChipsToFunds();
		std::cout << "Exiting program...";
		break;
	default:
		std::cout << "Invalid Input";
		break;
	}
}

int main() {
	User *user = new User;
	bool end{};

	do{
		printInstructions();
		menuChoice(input(), user, end);
	} while (!end);
	return 0;
}