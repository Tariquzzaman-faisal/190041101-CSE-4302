#include <iostream>
using namespace std;
class Calculator
{
private:
    int value;

public:
    Calculator() : value(0)
    {
    }
    Calculator(int x) : value(x)
    {
    }
    int getValue()
    {
        return value;
    }
    void setValue(int _value)
    {
        value = _value;
    }
    void add(int _value)
    {
        value += _value;
    }
    void substract(int _value)
    {
        value -= _value;
    }
    void multiply(int _value)
    {
        value *= _value;
    }
    void divideBy(int _value)
    {
        if (_value)
            value /= _value;
        else
            cout << "Error : divide by 0 is undefined." << endl;
    }
    void clear()
    {
        value = 0;
    }
    void display()
    {
        cout << "Calculator Display:" << value << endl;
    }
    ~Calculator()
    {
        cout << "Calculator object is destroyed." << endl;
    }
};

int main()
{
    Calculator calc;
    calc.add(10);
    calc.display();
    calc.add(7);
    calc.display();
    calc.multiply(31);
    calc.display();
    calc.substract(42);
    calc.display();
    calc.divideBy(7);
    calc.display();
    calc.divideBy(0);
    calc.display();
    calc.add(3);
    calc.display();
    calc.substract(1);
    calc.display();
    calc.clear();
    calc.display();
    return 0;
}