#include<bits/stdc++.h>
using namespace std;

int main()
{
    int ara[20];
    set <int> s;
    int j=0;
    for(int i=0;i<10;i++)
    {
        if(i%2==1)
            s.insert(i);
        else
        {
            ara[j++]=i;
        }
    }

    vector <int> v(10);
    //Merging two containers into one
    merge(ara, ara+5, s.begin(), s.end(), v.begin());
    
    for(auto i = v.begin(); i!= v.end(); i++)
    {
        cout<<*i<<endl;
    }

    return 0;
}