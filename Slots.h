#ifndef SLOTS_H
#define SLOTS_H

class Slots{
private:
	__int16 m_slotNumbers[3][3];
	int m_chips{};
	__int16 m_chipsPlaced{};
public:
	void setRandomNumbers(__int16 m_slotNumbers[3][3]);
	__int16 setChipsPlaced(int& m_chips);
	void checkIfWon(__int16 m_slotNumbers[3][3], __int16& placedChips);
	void playGame();
	void printSlotNumbers(__int16 m_slotNumbers[3][3])const;
	int getChips()const;
	void printInstructions()const;
	bool checkContinue();
	void playSFX(int num);
	Slots(int &playerChips);
	~Slots();
};
#endif