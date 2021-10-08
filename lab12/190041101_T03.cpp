#include <bits/stdc++.h>
using namespace std;

template<typename T, int n>
class my_stack 
{
private:
    T ara[n];
    int top=-1;
public:
    class EmptyStack
    {
        public:
        string msg;
        EmptyStack(string _msg)
        {
            msg = _msg;
        }
    };
    bool push(T x)
    {

        if(top < n-1)
        {
            ara[++top] = x;
            cout<<"Pushed "<<x<<endl;
            return true;
        }
        else
        {
            throw EmptyStack("Cannot push as Stack is full\n");
        }
    }

    T pop()
    {
        if(top != -1)
        {
            T x = ara[top--];
            return x;
        }
        else
        {
            throw EmptyStack("Cannot pop as Stack is empty\n");
        }
    }

    T peek()
    {
        if (top < 0) {
        cout << "Stack is Empty\n";
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
    try
    {
        my_stack<int, 3>s1;
        s1.push(5);
        s1.push(6);
        s1.push(7);
        // s1.push(8);
        my_stack<char, 4>s2;
        cout<<s2.pop()<<endl;
    }
    catch(my_stack<int, 3>::EmptyStack ex)
    {
        cout<<ex.msg<<endl;
    }
    catch(my_stack<char, 4>::EmptyStack ex)
    {
        cout<<ex.msg<<endl;
    }
}

