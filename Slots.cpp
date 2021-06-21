#pragma comment(lib, "winmm.lib")
#include <iostream>
#include <ctime>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include <mmsystem.h>
#include "Slots.h"

Slots::Slots(int& playerChips) : m_chips{ playerChips }, m_slotNumbers{ {0,0,0}, {0,0,0}, {0,0,0} } {
}

void Slots::playGame() {
	bool leave{};
	printInstructions();
	playSFX(2);
	while (leave != true) {
		setChipsPlaced(m_chips);
		setRandomNumbers(m_slotNumbers);
		playSFX(1);
		printSlotNumbers(m_slotNumbers);
		checkIfWon(m_slotNumbers, m_chipsPlaced);
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
			__int16 randomNum{ 1 + rand() % (4 + 0) };
			m_slotNumbers[i][j] = randomNum;
		}
	}
}

void Slots::checkIfWon(__int16 m_slotNumbers[3][3], __int16& placedChips) {
	if (placedChips == 1) {
		if (m_slotNumbers[1][0] == m_slotNumbers[1][1] && m_slotNumbers[1][0] == m_slotNumbers[1][2]) {
			std::cout << "\n*** WINNER + 100pts ***\n";
			playSFX(4);
			m_chips += (100 + m_chipsPlaced);
		}
		else {
			std::cout << "\n>> No numbers match <<\n";
			playSFX(5);
		}
	}
	else if (placedChips == 2) {
		if (m_slotNumbers[0][0] == m_slotNumbers[0][1] && m_slotNumbers[0][0] == m_slotNumbers[0][2] ||
			m_slotNumbers[1][0] == m_slotNumbers[1][1] && m_slotNumbers[1][0] == m_slotNumbers[1][2] ||
			m_slotNumbers[2][0] == m_slotNumbers[2][1] && m_slotNumbers[2][0] == m_slotNumbers[2][2]) {
			std::cout << "\n*** WINNER + 50pts ***\n";
			playSFX(4);
			m_chips += (50 + m_chipsPlaced);
		}
		else {
			std::cout << "\n>> No numbers match <<\n";
			playSFX(5);
		}
	}
	else if (placedChips == 3) {
		if (m_slotNumbers[0][0] == m_slotNumbers[0][1] && m_slotNumbers[0][0] == m_slotNumbers[0][2] ||
			m_slotNumbers[1][0] == m_slotNumbers[1][1] && m_slotNumbers[1][0] == m_slotNumbers[1][2] ||
			m_slotNumbers[2][0] == m_slotNumbers[2][1] && m_slotNumbers[2][0] == m_slotNumbers[2][2] ||
			m_slotNumbers[0][0] == m_slotNumbers[1][1] && m_slotNumbers[0][0] == m_slotNumbers[2][2] ||
			m_slotNumbers[2][0] == m_slotNumbers[1][1] && m_slotNumbers[2][0] == m_slotNumbers[0][2]) {
			std::cout << "\n*** WINNER + 15pts ***\n";
			playSFX(4);
			m_chips += (15 + m_chipsPlaced);
		}
		else {
			std::cout << "\n>> No numbers match <<\n";
			playSFX(5);
		}
	}
}

__int16 Slots::setChipsPlaced(int &m_chips) {
	bool correct{};
	__int16 chips{};
	while (correct != true) {
		std::cout << "How many chips do you want to bet? (1,2,3)\n";
		std::cin >> chips;
		if (chips == 1 || chips == 2 || chips == 3) {
			m_chipsPlaced = chips;
			correct = true;
			playSFX(3);
			m_chips -= chips;
			std::cout << "\n** SPINNING **\n";
		}
		else {
			std::cout << "**Invalid number, must be 1, 2 or 3**\n";
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

void Slots::playSFX(int num){
	if (num == 1) {
		PlaySound(TEXT("slot.wav"), NULL, SND_SYNC);
	}
	else if (num == 2) {
		PlaySound(TEXT("start.wav"), NULL, SND_SYNC);
	}
	else if (num == 3) {
		PlaySound(TEXT("coin.wav"), NULL, SND_SYNC);
	}
	else if (num == 4) {
		PlaySound(TEXT("win.wav"), NULL, SND_SYNC);
	}
	else if (num == 5) {
		PlaySound(TEXT("fail.wav"), NULL, SND_SYNC);
	}
}

void Slots::printInstructions() const{
	std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	std::cout << "For slots you can place either 1,2,3 chip bets for each spin.\n";
	std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	std::cout << "1 chip \t \t" << "2 chips \t" << "3 chips \n";
	std::cout << "-------------" << "\t-------------\t" << "-------------\n";
	std::cout << "|   |   |   |" << "\t| - | - | - |\t" << "| -\\| - |/- |\n";
	std::cout << "-------------" << "\t-------------\t" << "-------------\n";
	std::cout << "| - | - | - |" << "\t| - | - | - |\t" << "| - | X | - |\n";
	std::cout << "-------------" << "\t-------------\t" << "-------------\n";
	std::cout << "|   |   |   |" << "\t| - | - | - |\t" << "| -/| - |\\- |\n";
	std::cout << "-------------" << "\t-------------\t" << "-------------\n";
	std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
}

int Slots::getChips() const {
	return m_chips;
}

Slots::~Slots(){
}
