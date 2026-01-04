#include <bits/stdc++.h>
using namespace std;
int maxDepth(string s)
{

    int maxi = 0;
    int count = 0;

    for (auto &it : s)
    {
        if (it == '(')
            count++;

        else if (it == ')')
            count--;

        maxi = max(maxi, count);
    }
    return maxi;
}
int main()
{

    return 0;
}