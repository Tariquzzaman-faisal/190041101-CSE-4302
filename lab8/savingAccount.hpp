#include "Account.hpp"
class savingsAccount : public Account
{
private:
	float interestRate;
	float monthlyDepositAmount;
	const static int accountPrefix;
	static int nextAccount;

	void _nextAccount()
	{

		this->nextAccount++;
	}

public:
	//constuctor
	savingsAccount(string str) : Account(), interestRate(0), monthlyDepositAmount(0)
	{
		_nextAccount();
	}
	savingsAccount(string accountName, double balance, double interestRate, double monthlyDepositAmount) :  Account(to_string(accountPrefix) + '-' + to_string(nextAccount), accountName, balance), interestRate(interestRate), monthlyDepositAmount(monthlyDepositAmount)
	{
		_nextAccount();
	}
	//destructor
	~savingsAccount()
	{
	}

	//setter
	void setInterestRate(float rate)
	{
		this->interestRate = rate;
	}
	void setMonthlyDepositAmount(float amount)
	{
		this->monthlyDepositAmount = amount;
	}

	//getter
	float getInterestRate() const
	{
		return interestRate;
	}
	float getMonthlyDeposit() const
	{
		return monthlyDepositAmount;
	}
	int getaccountPrefix() const
	{
		return accountPrefix;
	}
	void description() const
	{
		cout <<"Savings account\n"
			 << "Account Name: " << Account::getAccountName() << endl
			 << "Account Number: " << Account::getAccountNo() << endl
			 << "Current Balance: " << Account::getBalance() << endl
			 << "Interest rate: " << interestRate << "\nMonthly deposit amount: " << monthlyDepositAmount << "\nYou can withdraw your money any time\nThanks for staying with ABCD Bank\n-------------------------------\n";
	}
};

const int savingsAccount::accountPrefix = 200;
int savingsAccount::nextAccount = 1;