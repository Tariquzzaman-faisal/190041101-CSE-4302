#include "Account.hpp"

class currentAccount : public Account
{
private:
	const static int serviceCharge;
	const static int accountPrefix;
	static int nextAccount;

	void _nextAccount()
	{
		this->nextAccount++;
	}

public:
	//constructor
	currentAccount(string str="")
	{
		Account::setAccountNo(accountPrefix, nextAccount);
		Account::setAccountName(str);
		setBalance(0);
		_nextAccount();
	}
	currentAccount(string accountName, double balance) :  Account(to_string(accountPrefix) + '-' + to_string(nextAccount), accountName, balance)
	{
		_nextAccount();
	}

	//destructor
	~currentAccount()
	{
	}

	//getter
	int getServiceCharge() const
	{
		return this->serviceCharge;
	}
	int getAccountPrefix() const
	{
		return this->accountPrefix;
	}
	int getNextAccount() const
	{
		return this->nextAccount;
	}
	void description() const
	{
		cout <<"Current Account\n"
			 << "Account Name: " << Account::getAccountName() << endl
			 << "Account Number: " << Account::getAccountNo() << endl
			 << "Current Balance: " << Account::getBalance() << endl
			 << "Service charge: " << serviceCharge << "\nYou can withdraw your money any time\nThanks for staying with ABCD Bank\n-------------------------------\n";
	}
	//setter
	void setNextAccount(int val)
	{
		this->nextAccount = val;
	}
};
const int currentAccount::serviceCharge = 100;
const int currentAccount::accountPrefix = 100;
int currentAccount::nextAccount = 1;