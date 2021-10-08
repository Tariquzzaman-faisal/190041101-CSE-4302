#include <bits/stdc++.h>
using namespace std;

template<typename T>
T amax(T *ara,int size, int n)
{
    T ara2[size];
    for (int i = 0; i < size; i++)
    {
        ara2[i] = ara[i];
    }
    
    sort(ara2, ara2+size);
    
    return ara2[size-n];
}

int main()
{
    double a[5] = {1.1, 5.3, 4.2, 6.7, 8.9};
    cout<<amax(a, 5, 3)<<endl;

    int b[5] = {1, 2, 3, 4, 5};
    cout<<amax(b, 5, 3)<<endl;
}