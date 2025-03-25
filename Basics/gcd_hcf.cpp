#include <bits/stdc++.h>
using namespace std;

//suppose u want to calculate the lcm of two numbers
//use formaula x*y/gcd(x,y) 
int method1(int num1, int num2)
{
    int gcd = 0;
    for (int i = 1; i <= min(num1, num2); i++)
    {
        if (num1 % i == 0 && num2 % i == 0)
            gcd = i;
    }

    return gcd;
}

int euclidean(int num1, int num2)
{
    while (num1 != 0 && num2 != 0)
    {
        if (num1 > num2)
            num1 = num1 % num2;

        else
            num2 = num2 % num1;
    }

    if (num1 == 0)
        return num2;

    else
        return num1;
}

int main()
{

    cout << euclidean(12, 6);

    return 0;
}