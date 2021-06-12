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
	Blackjack(int& playerChips);
	void createDeck();
	int getPlayerScore()const;
	int getDealerScore()const;
	void playGame();
	void setPlayerScore(int &m_playerScore);
	void dealCard(int &m_playerScore);

	~Blackjack();
};

#endif