#include <bits/stdc++.h>
using namespace std;
// LC-455
int findContentChildren(vector<int> &g, vector<int> &s)
{

    int count = 0;

    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int i = 0;
    int j = 0;

    while (i < g.size() && j < s.size())
    {
        if (s[j] >= g[i])
        {
            count++;
            i++;
            j++;
        }

        else
            j++;
    }
    return count;
}
int main()
{

    return 0;
}