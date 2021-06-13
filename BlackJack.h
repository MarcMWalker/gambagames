#ifndef BLACKJACK_H
#define BLACKJACK_H
#include <array>
#include <string>

class Blackjack{
private:
	int m_playerScore{};
	int m_dealerScore{};
	int m_chips{};
	std::string m_cardValue[14]{ "Ace", "Two", "Three", "Four", "Five",
								 "Six", "Seven", "Eight", "Nine", "Ten",
								 "Jack", "Queen", "King" };
public:
	Blackjack(int& playerChips);
	void createDeck();
	void printInstructions();
	int getPlayerScore()const;
	int getDealerScore()const;
	void playGame();
	void addPlayerScore(int points);
	void resetPlayerScore();
	void addDealerScore(int points);
	void resetDealerScore();
	void checkWinner(int &m_playerScore, int& m_dealerScore);
	int generateRandomNum();
	void dealCard();
	int getChips(int m_playerChips);
	~Blackjack();
};

#endif