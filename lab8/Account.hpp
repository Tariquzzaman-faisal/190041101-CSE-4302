#pragma once
#include <iostream>
using namespace std;

class Account
{

private:
	string accountNo;
	string accountName;
	float balance;

public:
	//constructor
	Account(string str="") : accountNo("-1"), accountName(str), balance(0.0)
	{
	}
	Account(string accountNo, string accountName, double balance) : accountNo(accountNo), accountName(accountName), balance(balance)
	{}
	//destructor
	~Account()
	{
	}

	//setter
	void setAccountName(string str)
	{

		this->accountName = str;
	}
	void setAccountNo(int prefix, int ac_no)
	{
		int acp = prefix;
		string ac = to_string(acp) + '-' + to_string(ac_no);
		this->accountNo = ac;
	}
	void setBalance(float balance)
	{

		this->balance = balance;
	}

	//getter
	string getAccountName() const
	{
		return this->accountName;
	}

	string getAccountNo() const
	{
		return this->accountNo;
	}
	float getBalance() const
	{
		return this->balance;
	}
	void description() const
	{
		cout << "----Welcome to ABCD bank----\n";
	}
};