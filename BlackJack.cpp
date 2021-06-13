#include "Blackjack.h"
#include "User.h"
#include <array>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

Blackjack::Blackjack(int& playerChips) : m_playerScore{ 0 }, m_dealerScore{ 0 }, m_chips{playerChips} {
}

void Blackjack::createDeck() {
	
}

void Blackjack::printInstructions(){
	std::cout << "How many chips would you like to place for the start: ";
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
		std::cout << m_cardValue[generateRandomNum()] << "\n";
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
	int num{ rand() % 12 + 1 };
	return num;
}

void Blackjack::dealCard(){
	
}

int Blackjack::getChips(int m_playerChips){
	return m_playerChips;
}

Blackjack::~Blackjack() {
}
