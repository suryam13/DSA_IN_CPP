#include <bits/stdc++.h>
using namespace std;
// nth natural number after removing all the elements containing 9;

long long findNth(long long n)
{

    // containing the digit 9 means it should consist of digits between 1 to 8 that is base 9 numbers

    long long ans = 0;
    int i = 0;

    while (n > 0)
    {
        int digit = n % 9;

        ans = digit * pow(10, i) + ans;
        i++;

        n = n / 9;
    }

    return ans;
}
int main()
{

    return 0;
}