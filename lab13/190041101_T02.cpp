#include <iostream>
using namespace std;

namespace type1
{
    int cout = 2;
}

namespace type2
{
    string cout = "Hello world";
}

int main()
{
    cout<<type1::cout<<endl<<type2::cout<<endl;
}