#include "Slots.h"
#include <iostream>

Slots::Slots(int& playerChips) : m_slotNumbers { {0,0,0}, {0,0,0}, {0,0,0} } {
}

void Slots::playGame() {
	printInstructions();
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
