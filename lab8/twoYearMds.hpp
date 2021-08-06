#include "monthlyDepositScheme.hpp"

class twoYearMDS : public monthlyDepositScheme
{
private:
	float MaximumInterest;

public:
	//constructor
	twoYearMDS(string str="")
	{
		monthlyDepositScheme::setAccountNo(getAccountPrefix(), getNextAccount());
		monthlyDepositScheme::setAccountName(str);
		setBalance(0);
		setMaximumInterest(0);
		setInterestRate(0);
		setMonthlyDepositAmount(0);
		_nextAccount();
	}
	//destructor
	~twoYearMDS()
	{
	}

	//getter
	float getMaximumInterest() const
	{
		return this->MaximumInterest;
	}
	void description() const
	{
		cout <<"Two Year Monthly Deposit Scheme\n"
			 << "Account Name: " << Account::getAccountName() << endl
			 << "Account Number: " << Account::getAccountNo() << endl
			 << "Current Balance: " << Account::getBalance() << endl
			 << "You need to deposit a fixed amount of money each month\nThanks for staying with ABCD Bank\n-------------------------------\n";
	}
	//setter
	void setMaximumInterest(float rate)
	{
		this->MaximumInterest = rate;
	}
};