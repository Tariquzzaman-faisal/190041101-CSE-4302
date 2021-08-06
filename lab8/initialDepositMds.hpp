#include "monthlyDepositScheme.hpp"

class initialDepositMDS : public monthlyDepositScheme
{
private:
	float MaximumInterest;
	float initialDepositAmount;

public:
	//constructor
	initialDepositMDS(string str)
	{
		monthlyDepositScheme::setAccountNo(getAccountPrefix(), getNextAccount());
		monthlyDepositScheme::setAccountName(str);
		setBalance(0);
		setMaximumInterest(0);
		setInitialDepositAmount(0);
		setInterestRate(0);
		setMonthlyDepositAmount(0);
		_nextAccount();
	}
	
	//destructor
	~initialDepositMDS()
	{
	}

	//getter
	float getinitialDepositAmount() const
	{
		return this->initialDepositAmount;
	}
	float getMaximumInterest() const
	{
		return this->MaximumInterest;
	}
	void description() const
	{
		cout <<"Initial Deposit MDS\n"
			 << "Account Name: " << Account::getAccountName() << endl
			 << "Account Number: " << Account::getAccountNo() << endl
			 << "Current Balance: " << Account::getBalance() << endl
			 << "You need to deposit atleast " << monthlyDepositScheme::getMonthlyDepositAmount() << " every month to get " << monthlyDepositScheme::getInterestRate() << '%' << " interest\n"
			 << "If you don't close within 2 years you will get maximum " << MaximumInterest << "% "
			 << "interest\nThanks for staying with ABCD Bank\n-------------------------------\n";
	}

	//setter
	void setInitialDepositAmount(float amount)
	{
		this->initialDepositAmount = amount;
	}
	void setMaximumInterest(float rate)
	{
		this->MaximumInterest = rate;
	}
};