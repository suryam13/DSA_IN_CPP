#include <bits/stdc++.h>
using namespace std;
int numberOfSubstrings(string s)
{
    // tricky to understand at first glimpse;
    unordered_map<char, int> mapy; // last seen index
    int i = 0;
    int cnt = 0;
    mapy['a'] = -1;
    mapy['b'] = -1;
    mapy['c'] = -1;

    while (i < s.size())
    {
        mapy[s[i]] = i;

        if (mapy[s[i]] != -1 || mapy[s[i]] != -1 ||
            mapy[s[i]] != -1) // means all are covered uptill now
        {
            int mini = min(mapy['a'], min(mapy['b'], mapy['c']));
            cnt = cnt + 1 + mini;
            // one for itself and rest are the one behinds it, as all would be substrings
        }

        i++;
    }
    return cnt;
}
int main()
{

    return 0;
}