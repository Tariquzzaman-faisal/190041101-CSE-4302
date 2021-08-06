#pragma once
#include "Account.hpp"

class monthlyDepositScheme : public Account
{

private:
	float interestRate;
	float monthlyDepositAmount;
	const static int accountPrefix;
	static int nextAccount;

	void _nextAccountNo()
	{
		this->nextAccount++;
	}

public:
	void setInterestRate(float _ir)
	{
		this->interestRate = _ir;
	}
	void setMonthlyDepositAmount(float amount)
	{
		this->monthlyDepositAmount = amount;
	}
	void _nextAccount(){
		this->nextAccount++;
	}
	//getter
	int getNextAccount() const
	{
		return this->nextAccount;
	}
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
};

const int monthlyDepositScheme::accountPrefix = 300;
int monthlyDepositScheme::nextAccount = 1;