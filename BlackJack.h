#ifndef BLACKJACK_H
#define BLACKJACK_H
#include <array>
#include <string>
#include <vector>
#include <ctime>

class Blackjack{
private:
	int m_playerScore{};
	int m_dealerScore{};
	int m_chips{};
	bool m_playerWin{};
	std::vector<std::string> m_cardValue{ "Ace", "Two", "Three", "Four", "Five",
								 "Six", "Seven", "Eight", "Nine", "Ten",
								 "Jack", "Queen", "King", "Ace Upper"};
public:
	Blackjack(int& playerChips);
	void printInstructions();
	void anotherInstructions();
	bool playerInput();
	int getPlayerScore()const;
	int getDealerScore()const;
	void playGame();
	void addPlayerScore(int points);
	void resetPlayerScore();
	void addDealerScore(int points);
	void resetDealerScore();
	int generateRandomNum();
	void dealCards(int &playerScore, int chipsPlaced);
	int getChips()const;
	int calculateCards(std::vector<int>&cards)const;
	void printValueToText(std::vector<int>&cards)const;
	~Blackjack();
};

#endif