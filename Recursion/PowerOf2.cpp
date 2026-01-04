#include <bits/stdc++.h>
using namespace std;

int power(int n)
{
    // base case
    if (n == 0)
        return 1;

    return 2 * power(n - 1);
}

int anyPower(int i,int n)
{
    // base case
    if (n == 0)
        return 1;

    return i * anyPower(i,n - 1);
}
int main()
{   
    cout<<power(10)<<endl;
    cout<<anyPower(5,4);


    return 0;
}