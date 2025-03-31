#include<bits/stdc++.h>
using namespace std;

 int main()
{
    int a=5;
    float b=10.1;//compiler promotes larger data type untill the number is 10.0,it can be 10.2,10,8 or other 
    cout<<a+b<<endl;

    char ch='A';
    cout<<'A'+1<<endl;

    int x=5;
    float y=3.14;
    float c=x+(int)y;
    cout<<c<<endl;
    return 0;
}