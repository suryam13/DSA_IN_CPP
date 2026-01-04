#include <bits/stdc++.h>
using namespace std;

int fact(int n)
{

    // base case
    if (n == 1 || n == 0)
        return 1;

    // recursive relation
    int ans = n * fact(n - 1);
    return ans;

    // processing
}

int main()
{
    int i = 5;

    int ans = fact(i);

    cout << ans << endl;

    return 0;
}