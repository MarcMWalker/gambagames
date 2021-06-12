#ifndef BLACKJACK_H
#define BLACKJACK_H
#include <array>
#include <string>

class Blackjack{
private:
	int m_playerScore{};
	int m_dealerScore{};
	int m_playerChips{};
	std::string m_cardValue[14]{ "Ace", "Two", "Three", "Four", "Five",
									"Six", "Seven", "Eight", "Nine", "Ten",
									"Jack", "Queen", "King" };
public:
	void createDeck();
	int getPlayerScore();
	int getDealerScore();
	
	~Blackjack();

	Blackjack(int &playerChips);
};

#endif