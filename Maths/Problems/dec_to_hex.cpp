#include <bits/stdc++.h>
using namespace std;
//Lc-405
string toHex(int num)
{

    unsigned int n = num;
    // did this to make sure that that the -ve number is treated as +ve number although the bit representations remains
    // the same but the gact is earlier the MSB was 1 so it was taking negative number

    string ans;
    while (n > 15)
    {
        int mod = n % 16;

        char ch = '0' + mod;

        if (mod >= 10 && mod <= 15)
            ch = 'a' + (mod - 10);

        ans.push_back(ch);
        n = n / 16;
    }

    if (n < 10)
        ans.push_back('0' + n);

    else
        ans.push_back('a' + (n - 10));

    reverse(ans.begin(), ans.end());

    return ans;
}
int main()
{

    return 0;
}