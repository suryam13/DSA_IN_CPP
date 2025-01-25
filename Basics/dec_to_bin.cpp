#include <bits/stdc++.h>
using namespace std;

int bin(int n)
{
    float ans = 0; // float because int not suitable in VS for this
    int i = 0;
    while (n != 0)
    {
        int digit = n & 1;

        ans = digit * pow(10, i) + ans; // to reverse according to compiler,if same according to compiler than the formula is ans=ans*10+digit

        n = n >> 1;
        i++;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;

    cout << bin(n);
    return 0;
}