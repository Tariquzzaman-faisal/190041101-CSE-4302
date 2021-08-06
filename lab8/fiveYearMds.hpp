#include "monthlyDepositScheme.hpp"

class fiveYearMDS : public monthlyDepositScheme
{
private:
	float minimumInterest;

public:
	//constructor
	fiveYearMDS(string str)
	{
		monthlyDepositScheme::setAccountNo(getAccountPrefix(), getNextAccount());
		monthlyDepositScheme::setAccountName(str);
		setBalance(0);
		setMinimumInterest(0);
		setInterestRate(0);
		setMonthlyDepositAmount(0);
		_nextAccount();
	}
	//destructor
	~fiveYearMDS()
	{
	}

	//getter
	float getMinimumInterest() const
	{
		return this->minimumInterest;
	}
	void description() const
	{
		cout <<"Five Year Monthly Deposit Scheme\n"
			 << "Account Name: " << Account::getAccountName() << endl
			 << "Account Number: " << Account::getAccountNo() << endl
			 << "Current Balance: " << Account::getBalance() << endl
			 << "You need to deposit a fixed amount of money each month\nThanks for staying with ABCD Bank\n-------------------------------\n";
	}
	//setter
	void setMinimumInterest(float rate)
	{
		this->minimumInterest = rate;
	}
};