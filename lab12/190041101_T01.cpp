#include <bits/stdc++.h>
using namespace std;

template<typename T, int n>
class my_stack 
{
private:
    T ara[n];
    int top=-1;
public:

    bool push(T x)
    {
        if(top >= n-1)
        {
            cout<<"Stack Overflow!"<<endl;
            return false;
        }
        else
        {
            ara[++top] = x;
            cout<<"Pushed "<<x<<endl;
            return true;
        }
    }

    T pop()
    {
        if (top<0)
        {
            cout<<"Stack is empty\n";
            return 0;
        }   
        else 
        {
            T x = ara[top--];
            return x;
        }
    }

    T peek()
    {
        if (top < 0) {
        cout << "Stack is Empty";
        return 0;
        }
        else {
            T x = ara[top];
            return x;
        }
    }

};

int main()
{
    my_stack<int, 3>s1;
    s1.push(5);
    s1.push(6);
    s1.push(7);
    s1.push(8);
    cout<<s1.pop()<<endl;
    cout<<s1.peek()<<endl;

    cout<<"Second type\n";

    my_stack<char, 4>s2;
    s2.push('A');
    s2.push('B');
    s2.push('C');
    s2.push('D');
    cout<<"First element: "<<s2.peek()<<endl;
    cout<<s2.pop()<<endl;
    cout<<s2.pop()<<endl;
    cout<<s2.pop()<<endl;
    cout<<s2.pop()<<endl;
    cout<<s2.pop()<<endl;
}

