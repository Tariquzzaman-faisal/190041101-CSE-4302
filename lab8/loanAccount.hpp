#include "Account.hpp"

class LoanAccount : public Account
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
	//constructor
	LoanAccount(string str)
	{
		Account::setAccountNo(accountPrefix, nextAccount);
		Account::setAccountName(str);
		setBalance(0);
		setInterestRate(0);
		setMonthlyDepositAmount(0);
		_nextAccount();
	}
	LoanAccount(string accountName, double balance, double interestRate, double monthlyDepositAmount) :  Account(to_string(accountPrefix) + '-' + to_string(nextAccount), accountName, balance), interestRate(interestRate), monthlyDepositAmount(monthlyDepositAmount)
	{
		_nextAccount();
	}
	//destructor
	~LoanAccount()
	{
		this->nextAccount--;
	}

	//setter
	float setInterestRate(float _ir)
	{
		this->interestRate = _ir;
	}
	float setMonthlyDepositAmount(float amount)
	{
		this->monthlyDepositAmount = amount;
	}
	//getter
	float getInterestRate() const
	{
		return this->interestRate;
	}
	float getMonthlyDepositAmount() const
	{
		return this->monthlyDepositAmount;
	}
	int getAccountPrefix() const
	{
		return this->accountPrefix;
	}
	void description() const
	{
		cout <<"Loan Account\n"
			 << "Account Name: " << Account::getAccountName() << endl
			 << "Account Number: " << Account::getAccountNo() << endl
			 << "Current Loan Amount: " << Account::getBalance() << endl
			 << "Monthly downpayment is " << monthlyDepositAmount << " and interest rate is " << interestRate << '%' << "\nThanks for staying with ABCD Bank\n-------------------------------\n";
	}
};

const int LoanAccount::accountPrefix = 900;
int LoanAccount::nextAccount = 1;