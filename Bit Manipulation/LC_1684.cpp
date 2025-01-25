#include <bits/stdc++.h>
using namespace std;
int countConsistentStrings(string allowed, vector<string> &words)
{
    set<int> st;
    int count = 0;
    int dummy = 0;

    for (auto it : allowed)
        st.insert(it);

    for (auto it : words)
    {
        string s = it;

        for (auto i : s)
        {
            if (st.find(i) == st.end())
                break;

            else
                dummy++;
        }
        if (dummy == s.size())
            count++;

        dummy = 0;
    }

    return count;
}

int countConsistentStrings(string allowed, vector<string> &words)
{

    // using bit manipulation
    // we will consider a mask which would contain 1 or 0 depending on
    // whether the character is present or not

    int mask = 0;
    int count = 0;
    // there are 26 unique letters possible a would map to 0

    for (auto ch : allowed)
    {
        mask = mask | (1 << (ch - 'a'));

        // suppose ch is b then 1 would be left shifted by 1 and to set that
        // position in mask it would be ored by that resulting into setting
        // that particular position in the mask
    }

    for (auto word : words)
    {
        bool check = true;

        for (auto ch : word)
        {
            // now i will check whether this char is set or not in the mask
            if (((mask >> (ch - 'a')) & 1) == 0)
            // means it is not set hence not present in the allowed string
            {
                check = false;
                break;
            }
        }
        if (check)
        {
            count++;
        }
    }
    return count;
}
int main()
{

    return 0;
}
