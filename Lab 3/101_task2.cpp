#include<iostream>
using namespace std;

class RationalNumber
{
    private:
        int numenator, denominator;
    public:
    RationalNumber():numenator(0), denominator(1)
    {

    }
    void assign(int nom, int denom){
        if(denom == 0){
            cout<<"Error\n";
            return;
        } 
        numenator = nom;
        denominator = denom;
    }
    double convert(){
        double d = (double)numenator/(double)denominator;
        return d;
    }
    void invert(){
        if(numenator == 0){
            cout<<"Error\n";
            return;
        }
        swap(numenator, denominator);
        cout<<"Inverted\n";
    }
    void print(){
        cout<<"The rational number is: "<<numenator<<"/"<<denominator<<endl;
    }
};

void mainMenu(){
    cout<<"What do you wanna do?\n1.Assign\n2.Convert\n3.Invert\n4.Print\n5.Exit\nOption: ";
}

int main(){
    RationalNumber r;
    bool runProgram = true;
    int option;
    while(runProgram){
        mainMenu();
        cin >> option;
        switch (option)
        {
        case 1:
            int nom, denom;
            cout<<"Nominator: ";
            cin >> nom;
            cout<<"Denominator: ";
            cin >> denom;
            r.assign(nom, denom);
            break;
        case 2:
            cout<<"Double result: "<<r.convert()<<"\n";
            break;
        case 3:
            r.invert();
            break;
        case 4:
            r.print();
            break;
        default:
        runProgram = false;
            break;
        }
    }
}