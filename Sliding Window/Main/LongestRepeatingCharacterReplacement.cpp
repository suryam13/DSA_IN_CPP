#include <bits/stdc++.h>
using namespace std;
int characterReplacement(string s, int k)
{

    int i = 0;
    int maxVal = INT_MIN;
    int maxSize = 0;
    map<char, int> mapy;
    int j = 0;

    while (i < s.size())
    {
        mapy[s[i]]++;

        // finding max in mapy
        for (auto it : mapy)
            maxVal = max(maxVal, it.second);

        // due to this we will get to know how many characters are to be changed
        if ((i - j + 1) - maxVal <= k)
            maxSize = max(maxSize, i - j + 1);

        // if not possible to consider then simply move the j by decrementing char of j
        else
        {
            mapy[s[j]]--;
            j++;
        }

        i++;
    }

    return maxSize;
}
int main()
{

    return 0;
}