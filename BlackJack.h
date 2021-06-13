#ifndef BLACKJACK_H
#define BLACKJACK_H
#include <array>
#include <string>
#include <vector>

class Blackjack{
private:
	int m_playerScore{};
	int m_dealerScore{};
	int m_chips{};
	bool m_playerWin{};
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
	void dealCards(int &playerScore);
	int getChips(int m_playerChips);
	int calculateCards(std::vector<int>cards)const;
	~Blackjack();
};

#endif