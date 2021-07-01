#include <iostream>
#include <cstring>
using namespace std;

class Product
{
private:
    char Pname[50];
    double discount, unitPrice;

public:
    Product() : Pname("x"), discount(0.5), unitPrice(10.0)
    {
    }

    void assignName(char name[])
    {
        strcpy(Pname, name);
    }
    void setPrice(double price)
    {
        unitPrice = price;
    }
    void setDiscPercent(double percent)
    {
        if(percent < 0 || percent > 10) {
            cout<<"Error\n";
            return;
        }
        discount = percent;
    }
    double getSellingPrice(int nos)
    {
        double priceRatio = (100 - discount) / 100;
        double total = nos * unitPrice * priceRatio;
        return total;
    }
    void display()
    {
        cout << Pname << " has a unit price of BDT " << unitPrice << ". Current discount " << discount << "%.\n";
    }
};

void mainMenu(){
    cout<<"What do you want to do?\n1.Assign name\n2.Set Price\n3.set Discount\n4.Get selling price\n5.Display\n6.Exit\nOption: ";
}

int main(){
    Product p;
    bool runProgram = true;
    int option;
    while (runProgram)
    {
        mainMenu();
        cin >> option;
        switch (option)
        {
        case 1:
            cout<<"Give name: ";
            char name[50];
            getchar();
            gets(name);
            p.assignName(name);
            break;
        case 2:
            double price;
            cout<<"Price: ";
            cin >> price;
            p.setPrice(price);
            break;
        case 3:
            cout<<"Discount: ";
            double discount;
            cin >> discount;
            p.setDiscPercent(discount);
            break;
        case 4:
            cout<<"No. of items: ";
            int items;
            cin >> items;
            cout<<"Selling price: ";
            cout<<p.getSellingPrice(items)<<"\n";
            break;
        case 5:
            p.display();
            break;
        default:
            runProgram = false;
            break;
        }
    }
    
}