#include <bits/stdc++.h>
using namespace std;
// GFG

int longestKSubstr(string s, int k)
{

    unordered_map<char, int> mapy;

    int i = 0;
    int j = 0;
    int maxlen = -1;

    while (i < s.size())
    {
        mapy[s[i]]++;

        if (mapy.size() == k)
        {
            maxlen = max(maxlen, i - j + 1);
        }

        // else if(mapy.size()>k) //means we have to shrink
        // {
        //     mapy[s[j]]--;

        //     if(mapy[s[j]]==0)
        //     mapy.erase(s[j]); //if count becomes 0 then erase

        //     j++;

        // }

        while (mapy.size() > k)
        {
            mapy[s[j]]--;

            if (mapy[s[j]] == 0)
                mapy.erase(s[j]); // if count becomes 0 then erase

            j++;
        }

        i++;
    }
    return maxlen;
}
int main()
{

    return 0;
}