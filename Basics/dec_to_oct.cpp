#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
long long decimalToOctal(int x)
{

    long long ans = 0;
    int i = 0;

    while (x != 0)
    {
        long long digit = x % 8;
        // since it is octal so mod would be done by 8

        ans = (digit * pow(10, i)) + ans;

        x = x / 8;
        i++;
        // since the numbering is to be followed from 0 to 7
    }
    return ans;
}

long long decimalToOctal(int n)
{

    string ans;
    while (n > 7)
    {
        int mod = n % 8;
        char ch = '0' + mod;
        ans.push_back(ch);
        n = n / 8;
    }
    ans.push_back('0' + n);
    reverse(ans.begin(), ans.end());

    return stoll(ans);
}
int main()
{

    return 0;
}