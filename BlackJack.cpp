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

int Blackjack::generateRandomNum(){
	srand(time(NULL));
	int num{ (rand() % 13 + 1) - 1 };
	if (num > 8 && num < 13) {
		return 10;
	}
	else {
		return num;
	}
}

void Blackjack::dealCards(int& playerScore, int chipsPlaced){
	std::vector<int>playerCardTotal{};
	std::vector<int>dealerCardTotal{};
	bool playerSkip{};

	dealerCardTotal.push_back(generateRandomNum());
	dealerCardTotal.push_back(generateRandomNum());
	int dealerPoints{ calculateCards(dealerCardTotal) };

	playerCardTotal.push_back(generateRandomNum());
	playerCardTotal.push_back(generateRandomNum());
	int playerPoints{};

	std::cout << "Dealer Score: " << dealerCardTotal.at(0) << " ??? " << "\n";
	std::cout << "Player Score: " << calculateCards(playerCardTotal) << "\n";
	printValueToText(playerCardTotal);
	
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
				printValueToText(playerCardTotal);
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
		playerPoints = calculateCards(playerCardTotal);
		//int card{generateRandomNum()};
	}

	if (calculateCards(playerCardTotal) == 21) {
		std::cout << "WINNER!";
		std::cout << "You collected " << chipsPlaced * 2;
		m_chips += (chipsPlaced * 2);
		m_playerWin = true;
		end = true;
	}

	//Dealers turn if player below 21
	if (playerPoints < 21) {
		while (dealerPoints < playerPoints && dealerPoints < 22) {
			dealerCardTotal.push_back(generateRandomNum());
			dealerPoints = calculateCards(dealerCardTotal);
		}
	}

	if (playerPoints <= dealerPoints && dealerPoints < 22) {
		std::cout << "Dealer Wins";
		m_playerWin = false;
		end = true;
	}

	if (dealerPoints > 21) {
		std::cout << "WINNER! Dealer went bust...";
		std::cout << "You collected " << chipsPlaced * 2;
		m_chips += (chipsPlaced * 2);
		m_playerWin = true;
		end = true;
	}

	if (playerPoints > 21) {
		std::cout << "BUST! ";
		m_playerWin = false;
		end = true;
	}
}

int Blackjack::getChips()const{
	return Blackjack::m_chips;
}

int Blackjack::calculateCards(std::vector<int>&cards)const {
	int total{};
	for (int i : cards) {
		total += i;
	}
	return total;
}

void Blackjack::printValueToText(std::vector<int>& cards) const {
	for (int i{ 0 }; i < cards.size(); i++) {
		int copy{ cards.at(i) };
		std::cout << Blackjack::m_cardValue[copy-1] << " | ";
	}
}

Blackjack::~Blackjack() {
}
