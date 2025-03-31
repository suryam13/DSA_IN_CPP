#include <bits/stdc++.h>
using namespace std;

int decimal(int n)
{
    int i = 0;
    int ans = 0;

    while (n != 0)
    {
        int digit = n % 10;

        if (digit == 1)
            ans = (pow(2, i) + ans);

        n = n / 10;
        i++;
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;

    cout << decimal(n);

    return 0;
}