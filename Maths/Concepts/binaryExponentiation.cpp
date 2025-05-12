#include <bits/stdc++.h>
using namespace std;
//TC: O(log n) n is the power
long long BinaryExpo(long long a, long long b)
{
    if (b == 0)
        return 1;

    if (b < 0) // in negative case, suppose 2^-4 so it would be 1/2^4 which would be (1/2)^4
        return BinaryExpo(1 / a, -b);

    else if (b % 2 == 0) // means power is even,so power would be half and a*a
        return BinaryExpo(a * a, b / 2);

    else // means power is odd
        return a * BinaryExpo(a * a, b / 2);
}

// WITH MODULO
long long MOD = 1e9 + 7;

long long BinaryExpo(long long a, long long b)
{
    if (b == 0)
        return 1;

    else if (b % 2 == 0) // means power is even,so power would be half and a+a
        return (BinaryExpo((a % MOD * a % MOD) % MOD, b / 2)) % MOD;

    else // means power is odd
        return (a % MOD * BinaryExpo((a % MOD * a % MOD) % MOD, (b - 1) / 2)) % MOD;
}

int main()
{

    return 0;
}