#pragma comment(lib, "winmm.lib")
#include<iostream>
#include <ctime>
#include "Slots.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include<Windows.h>
#include <mmsystem.h>

Slots::Slots(int& playerChips) : m_chips{ playerChips }, m_slotNumbers{ {0,0,0}, {0,0,0}, {0,0,0} } {
}

void Slots::playGame() {
	bool leave{};
	printInstructions();
	while (leave != true) {
		chipsPlaced = setChipsPlaced(m_chips);
		setRandomNumbers(m_slotNumbers);
		playSFX();
		printSlotNumbers(m_slotNumbers);
		leave = checkContinue();
	}
}

void Slots::printSlotNumbers(__int16 m_slotNumbers[3][3]) const{
	std::cout << "-------------\n";
	std::cout << "| " << m_slotNumbers[0][0] << " | " << m_slotNumbers[0][1] << " | " << m_slotNumbers[0][2] << " |\n";
	std::cout << "-------------\n";
	std::cout << "| " << m_slotNumbers[1][0] << " | " << m_slotNumbers[1][1] << " | " << m_slotNumbers[1][2] << " |\n";
	std::cout << "-------------\n";
	std::cout << "| " << m_slotNumbers[2][0] << " | " << m_slotNumbers[2][1] << " | " << m_slotNumbers[2][2] << " |\n";
	std::cout << "-------------\n";
}

void Slots::setRandomNumbers(__int16 m_slotNumbers[3][3]) {
	srand((int)time(0));
	for (int i{ 0 }; i < 3; ++i) {
		for (int j{ 0 }; j < 3; ++j) {
			__int16 randomNum{ 1 + rand() % (7 + 0) };
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
		}
		else {
			std::cout << "**Invalid number, must be 1, 4 or 7**\n";
			correct = false;
		}
	}
	return chips;
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

void Slots::playSFX(){
	bool play = PlaySound(TEXT("slot.wav"), NULL, SND_SYNC);
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
