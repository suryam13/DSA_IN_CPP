#include <bits/stdc++.h>
using namespace std;

// GFG
int countSubstr(string &s, int k)
{

    int cnt = 0;
    int n = s.size();
    int i = 0, j = 0, track = 0, dummy = 0;

    unordered_map<char, int> mapy;

    while (j < n)
    {
        mapy[s[j]]++;

        // shrink the i pointer to maintain k again
        while (mapy.size() > k)
        {
            mapy[s[i]]--;

            if (mapy[s[i]] == 0)
                mapy.erase(s[i]);

            i++;
            dummy = 0; // reset dummy to 0 as new sequence starts
        }

        if (mapy.size() == k)
            cnt++;

        // now figure out how many more combinations can be added to this by coming from left side
        // it is necessary because we cannot condier all the combinations of the left side ex: k=2 and s="aabb" so here when j comes at last
        // the bb combination cant be taken so we have to come from left 2 so we came to know that we can make more 2 combinations for this
        // right side i.e. abb and aabb and maintain this count for further usage for eg if a comes in the string aabba so here we have
        // more two combinations ba and bba in addition to previous 2 so just add in that dummy count and add to dummy to the main cnt
        // and once we shrink i as the size becomes more than k so reset dummy as new sequenvce starts

        while (mapy.size() == k)
        {
            mapy[s[i]]--;

            if (mapy[s[i]] == 0)
                mapy.erase(s[i]);

            i++;

            if (mapy.size() < k)
            {
                i--;
                mapy[s[i]]++;
                break;
            }

            dummy++;
        }

        cnt += dummy;

        j++;
    }

    return cnt;
}
int main()
{

    return 0;
}