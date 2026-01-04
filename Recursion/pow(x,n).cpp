#include <bits/stdc++.h>
using namespace std;
// LC-50
// codestorywithmik-refer video
/*
if the we have to calculate the powerof 2 raise to 10
since power is 10 it can written in the form n/2 hence (x*x) power n/2

if the we have to calculate the powerof 2 raise to 9
since power is 9 it cannot be written in the form n/2 hence take one x outside so (x*x) power n-1/2 nd then at last multiply x   ans--> x *( (x*x) raise to n-1/2 )

to deal with negative powers look into the code as 5 to the power -2 can be written as(1/5) raise to power 2 so ans--> (1/x raise to -n)


note: refer video for range issue dealing with negatives as the range is -2^31 to 2^31-1 so if -2^31 is converted into positive so it would become 2^31 which would be out of bound so for that consider the power entity n as long instead of int to deal with such  issues
*/

double funct(double x, long n)
{
    // concept of exponentiation
    if (n == 0)
        return 1;

    if (n < 0) // means it is negative,so would call the function to make it positive
        return funct(1 / x, -n);

    if (n % 2 == 0) // mean the power is even
        return funct(x * x, n / 2);

    // else if(n%2==1) //means the power is odd
    return x * funct(x * x, (n - 1) / 2);
}

double myPow(double x, int n)
{
    return funct(x, n);
}

/* ITERATIVE APPROACH */
double funct(double x, long n)
{
    double result = 1;
    bool isNegative = false;

    // Handle negative exponent by converting to positive
    if (n < 0)
    {
        x = 1 / x;
        n = -n;
    }

    while (n > 0)
    {
        if (n % 2 == 1)
        {                // If n is odd
            result *= x; // Multiply result by the current base
        }
        x *= x; // Square the base (same as x*x)
        n /= 2; // Halve the exponent
    }

    return result;
}

int main()
{
    cout << funct(2.00000, 10);
    return 0;
}