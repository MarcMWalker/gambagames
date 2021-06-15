#include "Blackjack.h"
#include "User.h"
#include <array>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <windows.h>

Blackjack::Blackjack(int& playerChips) : m_playerScore{ 0 }, m_dealerScore{ 0 }, m_chips{playerChips} {
}

void Blackjack::printInstructions(){
	std::cout << "How many chips would you like to place for the start: ";
}

void Blackjack::anotherInstructions() {
	std::cout << "\n-------------------------------------\n";
	std::cout << "Another game Y/N?";
	std::cout << "\n-------------------------------------\n";
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
	int num{ (rand() % 13 + 1)};
	if (num > 8 && num < 14) {
		return 10;
	}
	else {
		return num;
	}
}

//Need to have a vector array to save current card type of player hand before becoming 10 in generate number function above
void Blackjack::dealCards(int& playerScore, int chipsPlaced){
	std::vector<int>playerCardTotal{};
	std::vector<int>dealerCardTotal{};
	bool playerSkip{};

	dealerCardTotal.push_back(generateRandomNum());
	srand((int)time(0));
	dealerCardTotal.push_back(generateRandomNum());
	int dealerPoints{ calculateCards(dealerCardTotal) };

	playerCardTotal.push_back(generateRandomNum());
	srand((int)time(0));
	playerCardTotal.push_back(generateRandomNum());
	int playerPoints{};

	std::cout << "Dealer Score: " << dealerCardTotal.at(0) << " ??? " << "\n";
	std::cout << "Player Score: " << calculateCards(playerCardTotal) << "\n";
	printValueToText(playerCardTotal);
	
	bool end{};
	while (end != true) {
		if (calculateCards(playerCardTotal) <= 21 && end != true) {
			
			std::cout << "\nAnother card Y/N: ";
			char choice{};
			std::cin >> choice;

			switch (choice) {
			case 'y':
			case 'Y':
				srand((int)time(0));
				playerCardTotal.push_back(generateRandomNum());
				std::cout << "\nPlayer Score: " << calculateCards(playerCardTotal) << "\n";
				printValueToText(playerCardTotal);
				break;
			case 'n':
			case 'N':
				srand((int)time(0));
				end = true;
				break;
			default:
				end = false;
				break;
			}
		}
		else { end = true; }
		playerPoints = calculateCards(playerCardTotal);
	}

	if (playerPoints == 21) {
		std::cout << "WINNER!\n";
		std::cout << "You collected " << chipsPlaced * 2;
		m_chips += (chipsPlaced * 2);
		m_playerWin = true;
		end = true;
	}

	else if (playerPoints > 21) {
		std::cout << "BUST! Dealer wins";
		m_playerWin = false;
		end = true;
	}

	if (playerPoints < 21) {
		while (dealerPoints < playerPoints && dealerPoints < 22) {
			dealerCardTotal.push_back(generateRandomNum());
			dealerPoints = calculateCards(dealerCardTotal);
			std::cout << "Dealer Score: " << dealerPoints << "\n";
		}
	}

	if (dealerPoints >= playerPoints && dealerPoints < 22) {
		std::cout << "Dealer Wins";
		m_playerWin = false;
		end = true;
	}

	if (dealerPoints > 21) {
		std::cout << "Dealer Score: " << calculateCards(dealerCardTotal) << "\n";
		std::cout << "WINNER! Dealer went bust...\n";
		std::cout << "You collected " << chipsPlaced * 2;
		m_chips += (chipsPlaced * 2);
		m_playerWin = true;
		end = true;
	}

	dealerCardTotal.clear();
	playerCardTotal.clear();
	playerPoints = 0;
	dealerPoints = 0;
	m_playerWin = false;
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
