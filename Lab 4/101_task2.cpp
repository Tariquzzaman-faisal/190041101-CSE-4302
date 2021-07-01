#include <iostream>
using namespace std;

class BankAccount
{
private:
    static int count;
    int accountNo;
    string HolderName, type;
    double currentBalance, minimumBalance;

public:
    BankAccount():HolderName("Null"), type("Null"), currentBalance(0), minimumBalance(0)
    {
        accountNo = ++count;
    }
    BankAccount(string _name, string _type, double _currentBalance, double _minBalance):HolderName(_name), type(_type), currentBalance(_currentBalance), minimumBalance(_minBalance)
    {
        accountNo = ++count;
    }
    double showBalance()
    {
        cout << currentBalance << endl;
    }
    void deposit(double _deposit)
    {
        if (_deposit <= 0)
            cout << "Deposit money has to be greater than 0!" << endl;
        else
            currentBalance += _deposit;
    }
    void withdrawal(double _withdraw)
    {
        if (_withdraw <= 0)
            cout << "Amount Cannot be negative" << endl;
        else if ((currentBalance - _withdraw) < minimumBalance)
            cout << "Cannot draw this amount, you have to keep a minimum balance" << endl;
        else
            currentBalance -= _withdraw;
    }
    double giveInterest(double iRate = 2.5)
    {
        double interest = currentBalance * iRate / 100.0;
        deposit(interest * 0.9);
    }
    void display(){
        cout << "Account of " << HolderName << " with account no " << accountNo << " is has a balance BDT " << currentBalance <<" and Minimum Balance: "<<minimumBalance<< endl;
    }
    ~BankAccount()
    {
        cout << "Account of " << HolderName << " with account no " << accountNo << " is destroyed with a balance BDT " << currentBalance << endl;
    }
};

int BankAccount::count = 0;

int main(){
    BankAccount acc1;
    acc1.display();
    BankAccount acc("Tariq", "Current", 100, 50);
    acc.display();
    acc.showBalance();
    acc.deposit(-50.0);
    acc.deposit(50.0);
    acc.showBalance();
    acc.withdrawal(-40);
    acc.withdrawal(40);
    acc.withdrawal(30);
    acc.showBalance();
    acc.giveInterest();
    acc.showBalance();
    return 0;
}