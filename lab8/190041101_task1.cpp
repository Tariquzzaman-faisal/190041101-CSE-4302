#include "currentAccount.hpp"
#include "savingAccount.hpp"
#include "loanAccount.hpp"
#include "fiveYearMds.hpp"
#include "initialDepositMds.hpp"
#include "twoYearMds.hpp"

int main(){
	currentAccount c1("Tariq");
	c1.setBalance(1000);
	c1.description();

	currentAccount c2("Alvee");
	c2.setBalance(4000);
	c2.description();

	currentAccount c3("Hasin", 100);
	c3.description();

	savingsAccount s("Navid", 140, 10, 5);
	s.description();

	savingsAccount s1("Reaz");
	s1.setInterestRate(3);
	s1.setBalance(6000);
	s1.setMonthlyDepositAmount(300);
	s1.description();

	savingsAccount s2("Saikat");
	s2.setInterestRate(3);
	s2.setBalance(50000);
	s2.setMonthlyDepositAmount(300);
	s2.description();

	LoanAccount l("Tasnim", 3600, 5, 340);
	l.description();
	
	LoanAccount l1("Alif");

	l1.setInterestRate(3);
	l1.setBalance(50000);
	l1.setMonthlyDepositAmount(300);
	l1.description();

	LoanAccount l2("Fahim");
	
	l2.setInterestRate(3);
	l2.setBalance(50000);
	l2.setMonthlyDepositAmount(300);
	l2.description();

	initialDepositMDS i1("Labib");
	
	i1.setBalance(34000);
	i1.setInitialDepositAmount(100);
	i1.setInterestRate(5);
	i1.setMaximumInterest(10);
	i1.setMonthlyDepositAmount(300);
	i1.description();

	initialDepositMDS i2("Farabi");
	i2.setBalance(34000);
	i2.setInitialDepositAmount(100);
	i2.setInterestRate(5);
	i2.setMaximumInterest(10);
	i2.setMonthlyDepositAmount(300);
	i2.description();

	twoYearMDS t1("Rafio");
	
	t1.description();

	twoYearMDS t2("Sami");
	t2.description();

	fiveYearMDS f1("Arif");
	
	f1.description();

	fiveYearMDS f2("Nahiyan");
	f2.description();

	return 0;
}