#include "User.h"
#include <iostream>

User::User() : m_chips{ 100 }, m_funds{1000} {
}

float User::getFunds() const{
	return m_funds;
}

int User::getChips() const {
	return m_chips;
}

void User::addFunds() {
	std::cout << "Amount to add to account: ";
	float addFund{};
	std::cin >> addFund;
	m_funds += addFund;
}

void User::setChips(int chips) {
	m_chips = chips;
}

void User::setFunds(float funds) {
	m_funds = funds;
}

void User::transferChipsToFunds() {
	m_funds += (m_chips * 100);
	m_chips = 0;
}

void User::transferFundsToChips() {
	std::cout << "How many chips would you like to purchase?\n";
	std::cout << "Amount: ";
	int amount{};
	std::cin >> amount;
	m_chips += amount;
	m_funds -= (amount * 100);
}

User::~User() {
}

