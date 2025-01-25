#include <bits/stdc++.h>
using namespace std;
int findTheLongestSubstring(string s)
{

    map<int, int> mapy;
    // codestorywithmik

    int mask = 0;    // initially it would be like 000....00000
    mapy[mask] = -1; // storing the initial calculation as -1 default start
    int maxi = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'a')
            mask = mask ^ (1 << 0); // xoring as to find out whether the current count made it even or odd....if comes 1 then odd and comes 0 then even occurence

        else if (s[i] == 'e')
            mask = mask ^ (1 << 1);

        else if (s[i] == 'i')
            mask = mask ^ (1 << 2);

        else if (s[i] == 'o')
            mask = mask ^ (1 << 3);

        else if (s[i] == 'u')
            mask = mask ^ (1 << 4);

        if (mapy.find(mask) != mapy.end()) // means this pattern is been observed earlier
        {
            maxi = max(maxi, i - mapy[mask]);
        }

        else
        {
            mapy[mask] = i;
        }
    }

    return maxi;
}
int main()
{

    return 0;
}