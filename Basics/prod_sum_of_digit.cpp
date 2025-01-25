#include <bits/stdc++.h>
using namespace std;

int subtractProductAndSum(int n)
{
    int prod = 1;
    int sum = 0;
    while (n != 0)
    {
        int digit = n % 10;
        prod = prod * digit;
        sum = sum + digit;

        n = n / 10;
    }
    int ans = prod - sum;
    return ans;
}

int main()
{

    return 0;
}