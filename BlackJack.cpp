#include "Blackjack.h"
#include "User.h"
#include <array>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

Blackjack::Blackjack(int& playerChips) : m_playerScore{ 0 }, m_dealerScore{ 0 }, m_chips{playerChips} {
}

void Blackjack::printInstructions(){
	std::cout << "How many chips would you like to place for the start: ";
}

void Blackjack::anotherInstructions() {
	std::cout << "Another game Y/N?";
}

bool Blackjack::playerInput() {
	char input{};
	std::cin >> input;

	switch (input) {
	case 'y':
	case 'Y':
		return false;
	case 'n':
	case 'N':
		return true;
	default:
		break;
	}
}

int Blackjack::getPlayerScore () const{
	return m_playerScore;
}

int Blackjack::getDealerScore () const{
	return m_dealerScore;
}

void Blackjack::playGame(){
	bool exit{};
	
	do {
		printInstructions();
		int num{};
		resetPlayerScore();
		resetDealerScore();
		int chipsPlaced{};
		std::cin >> chipsPlaced;
		m_chips -= chipsPlaced;
		dealCards(m_playerScore, chipsPlaced);
		anotherInstructions();
		exit = playerInput();
	} while (exit != true);
}

void Blackjack::addPlayerScore(int points){
	m_playerScore += points;
}

void Blackjack::resetPlayerScore(){
	m_playerScore = 0;
}

void Blackjack::addDealerScore(int points){
	m_dealerScore += points;
}

void Blackjack::resetDealerScore(){
	m_dealerScore = 0;
}

void Blackjack::checkWinner(int& m_playerScore, int& m_dealerScore){
}

int Blackjack::generateRandomNum(){
	srand(time(NULL));
	int num{ rand() % 11 + 1 };
	return num;
}

void Blackjack::dealCards(int& playerScore, int chipsPlaced){
	std::vector<int>playerCardTotal{};
	std::vector<int>dealerCardTotal{};
	bool playerSkip{};

	dealerCardTotal.push_back(generateRandomNum());
	dealerCardTotal.push_back(generateRandomNum());

	playerCardTotal.push_back(generateRandomNum());
	playerCardTotal.push_back(generateRandomNum());

	std::cout << "Dealer Score: " << dealerCardTotal.at(0) << " ??? " << "\n";
	std::cout << "Player Score: " << calculateCards(playerCardTotal) << "\n";
	
	bool end{};
	while (end != true) {
		if (calculateCards(playerCardTotal) <= 21 && end != true) {
			
			std::cout << "Another card Y/N: ";
			char choice{};
			std::cin >> choice;

			switch (choice) {
			case 'y':
			case 'Y':
				playerCardTotal.push_back(generateRandomNum());
				std::cout << "Player Score: " << calculateCards(playerCardTotal) << "\n";
				break;
			case 'n':
			case 'N':
				end = true;
				break;
			default:
				break;
			}
		}
		else { end = true; }
		//int card{generateRandomNum()};
	}

	if (calculateCards(playerCardTotal) == 21) {
		std::cout << "WINNER!";
		std::cout << "You collected " << chipsPlaced * 2;
		m_chips += (chipsPlaced * 2);
		end = true;
	}

	if (calculateCards(playerCardTotal) <= 21) {
		std::cout << "WINNER!";
		std::cout << "You collected " << chipsPlaced * 2;
		m_chips += (chipsPlaced * 2);
		end = true;
	}

	if (calculateCards(playerCardTotal) > 21) {
		std::cout << "BUST! ";
		m_playerWin = false;
		end = true;
	}
}

int Blackjack::getChips(){
	return Blackjack::m_chips;
}

int Blackjack::calculateCards(std::vector<int>cards)const {
	int total{};
	for (int i : cards) {
		total += i;
	}
	return total;
}

Blackjack::~Blackjack() {
}
