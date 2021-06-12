#ifndef USER_H
#define USER_H
class User{
private:
	float m_funds;
	int m_chips;
public:
	float getFunds()const;
	int getChips()const;
	void setFunds(float &m_funds);
	void setChips(int &m_chips);
	void transferFundsToChips(float& m_funds, int& m_chips);
	void transferChipsToFunds(float& m_funds, int& m_chips);
	User();
	~User();
};

#endif

