#ifndef SLOTS_H
#define SLOTS_H

class Slots{
private:
	__int16 m_slotNumbers[3][3];
	int m_chips{};
	__int16 chipsPlaced{};
public:
	void setRandomNumbers(__int16 m_slotNumbers[3][3]);
	//__int16 getNumbers(__int16 m_slotNumbers[])const;
	//void checkIfWon(__int16 m_slotNumbers[]);
	//void resetNumbers();
	void playGame();
	//void printSlotNumbers(__int16 m_slotNumbers[])const;
	int getChips()const;
	void printInstructions()const;
	bool checkContinue();
	__int16 setChipsPlaced(int &m_chips);
	//void userInput();
	Slots(int &playerChips);
	~Slots();
};
#endif