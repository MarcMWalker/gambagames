#include <iostream>
#include "User.h"
#include "BlackJack.h"
#include "Slots.h"

void printInstructions() {
	std::cout << "Welcome to the 'Gambling room'\n";
	std::cout << "------------------------------------\n";
	std::cout << "(A): Add funds to account\n";
	std::cout << "(B): Play Blackjack\n";
	std::cout << "(S): Play Slot Machines\n";
	std::cout << "(C): Change money to chips\n";
	std::cout << "(E): Exit Casino and cash out chips\n";
	std::cout << "------------------------------------\n";
}

void creatBlackJackGame(int &playerChips) {
	Blackjack* game = new Blackjack(playerChips);
	std::cout << "\n*** Now Playing Blackjack ***\n";
	game->playGame();
	playerChips = game->getChips();
}

void createSlotGame(int &playerChips) {
	Slots* game = new Slots(playerChips);
	std::cout << "\n*** Now Playing Slots ***\n";
	game->playGame();
	playerChips = game->getChips();
}

char input() {
	char choice{};
	std::cout << "Input>> ";
	std::cin >> choice;
	return choice;
}

void menuChoice(char input, User* user, bool &exit) {
	int playerChips = user->getChips();
	switch (input) {
	case 'a':
	case 'A':
		user->addFunds();
		break;
	case 'b':
	case 'B':
		creatBlackJackGame(playerChips);
		user->setChips(playerChips);
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
	case 's':
	case 'S':
		createSlotGame(playerChips);
		//user->transferChipsToFunds();
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