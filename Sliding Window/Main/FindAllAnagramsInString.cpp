#include <bits/stdc++.h>
using namespace std;
// LC-438
bool check(vector<int> &v)
{
    for (auto it : v)
    {
        if (it > 0)
            return false;
    }

    return true;
}
vector<int> findAnagrams(string s, string p)
{
    vector<int> ans;

    // Sliding window since the p string is of fixed size so would be acting
    // as window

    vector<int> v(26, 0); // in order to store the count of p
    for (char &it : p)
    {
        v[it - 'a']++;
    }

    int n = s.size();
    int k = p.size();
    int i = 0;
    int j = 0;

    while (i < n)
    {
        v[s[i] - 'a']--; // decreasing the count in v

        if (i - j + 1 == k) // means we have reached the window
        {
            if (check(v))
                ans.push_back(j); // if all the elements in v are less than
                                  // 1 means we have got

            // after checking move j forward and increment the char again at
            // that point
            v[s[j] - 'a']++;
            j++;
        }

        i++; // keep moving
    }

    return ans;
}
int main()
{

    return 0;
}