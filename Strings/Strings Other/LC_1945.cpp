#include <bits/stdc++.h>
using namespace std;

int getLucky(string s, int k)
{

    long long ans = 0;
    long long sum = 0;
    long long new_sum = 0;

    for (int i = 0; i < s.size(); i++)
    {
        ans = (s[i] - 'a' + 1);

        while (ans != 0)
        {
            int digit = ans % 10;
            new_sum = new_sum + digit;

            ans = ans / 10;
        }
    }

    cout << ans;

    while (k > 1)
    {

        while (new_sum != 0)
        {
            int digit = new_sum % 10;

            sum = sum + digit;

            new_sum = new_sum / 10;
        }

        k--;

        new_sum = sum;
        sum = 0;
    }

    return new_sum;
}
int main()
{

    return 0;
}