#include "Slots.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

Slots::Slots(int& playerChips) : m_chips{ playerChips }, m_slotNumbers{ {0,0,0}, {0,0,0}, {0,0,0} } {
}

void Slots::playGame() {
	bool leave{};
	printInstructions();
	while (leave != true) {
		chipsPlaced = setChipsPlaced(m_chips);
		setRandomNumbers(m_slotNumbers);
		leave = checkContinue();
	}
}

void Slots::setRandomNumbers(__int16 m_slotNumbers[3][3]) {
	for (int i{ 0 }; i < 3; i++) {
		for (int j{ 0 }; j < 3; j++) {
			__int16 randomNum{ rand() % (1 + 7) };
			srand(time(NULL));
			m_slotNumbers[i][j] = randomNum;
		}
	}
}

__int16 Slots::setChipsPlaced(int &m_chips) {
	bool correct{};
	__int16 chips{};
	while (correct != true) {
		std::cout << "How many chips do you want to bet? (1,4,7)\n";
		std::cin >> chips;
		if (chips == 1 || chips == 4 || chips == 7) {
			correct = true;
			m_chips -= chips;
			return chips;
		}
		else {
			std::cout << "**Invalid number, must be 1, 4 or 7**\n";
			correct = false;
		}
	}
}

bool Slots::checkContinue() {
	std::cout << "Spin again Y/N: ";
	char choice{};
	std::cin >> choice;
	switch (choice) {
	case 'y':
	case 'Y':
		return false;
	case 'n':
	case 'N':
		std::cout << "Leaving slots section now...\n";
		return true;
	default:
		return false;
	}
}

void Slots::printInstructions() const{
	std::cout << "For slots you can place either 1,4,7 chip bets for each spin.\n";
	std::cout << "1 chip gets you one middle row\n";
	std::cout << "-------------\n";
	std::cout << "|   |   |   |\n";
	std::cout << "-------------\n";
	std::cout << "| - | - | - |\n";
	std::cout << "-------------\n";
	std::cout << "|   |   |   |\n";
	std::cout << "-------------\n";

	std::cout << "4 chips get you 3 rows\n";
	std::cout << "-------------\n";
	std::cout << "| - | - | - |\n";
	std::cout << "-------------\n";
	std::cout << "| - | - | - |\n";
	std::cout << "-------------\n";
	std::cout << "| - | - | - |\n";
	std::cout << "-------------\n";

	std::cout << "7 chips get you 3 rows and 2 diagonal lines\n";
	std::cout << "-------------\n";
	std::cout << "| -\\| - |/- |\n";
	std::cout << "-------------\n";
	std::cout << "| - | X | - |\n";
	std::cout << "-------------\n";
	std::cout << "| -/| - |\\- |\n";
	std::cout << "-------------\n";
}

int Slots::getChips() const {
	return m_chips;
}
