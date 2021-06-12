#ifndef USER_H
#define USER_H
class User{
private:
	float m_funds;
	int m_chips;
public:
	float getFunds()const;
	int getChips()const;
	void addFunds();
	void setFunds(float funds);
	void setChips(int chips);
	void transferFundsToChips();
	void transferChipsToFunds();
	User();
	~User();
};

#endif

