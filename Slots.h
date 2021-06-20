#ifndef SLOTS_H
#define SLOTS_H

class Slots{
private:
	__int16 m_slotNumbers[3][3];
	int m_chips{};
public:
	//void setRandomNumbers(__int16 m_slotNumbers[]);
	//__int16 getNumbers(__int16 m_slotNumbers[])const;
	//void checkIfWon(__int16 m_slotNumbers[]);
	//void resetNumbers();
	void playGame();
	//void printSlotNumbers(__int16 m_slotNumbers[])const;
	int getChips()const;
	void printInstructions()const;
	//void userInput();
	Slots(int &playerChips);
	~Slots();
};
#endif