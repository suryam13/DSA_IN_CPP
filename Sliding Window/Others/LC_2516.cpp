#include <bits/stdc++.h>
using namespace std;
// tried it hrough recursion but got TLE
int mini = INT_MAX;

void solve(string &s, int k, int i, int j, vector<int> &v)
{
    if (v[0] >= k && v[1] >= k && v[2] >= k)
    {
        mini = min(mini, (v[0] + v[1] + v[2]));
        return;
    }

    if (i > j)
    {
        return;
    }

    // consider the left one
    v[s[i] - 'a']++;
    solve(s, k, i + 1, j, v);
    v[s[i] - 'a']--;

    // consider the right one
    v[s[j] - 'a']++;
    solve(s, k, i, j - 1, v);
    v[s[j] - 'a']--;
}
int takeCharacters(string s, int k)
{

    vector<int> v(3, 0);
    solve(s, k, 0, s.size() - 1, v);

    if (mini == INT_MAX)
        return -1;

    return mini;
}

// Sliding Window
int takeCharacters(string s, int k)
{

    int cnt_a = 0;
    int cnt_b = 0;
    int cnt_c = 0;
    int maxi = INT_MIN;

    // calcualting the total count of the characters
    for (auto it : s)
    {
        if (it == 'a')
            cnt_a++;
        else if (it == 'b')
            cnt_b++;
        else
            cnt_c++;
    }

    if (cnt_a < k || cnt_b < k || cnt_c < k) // means not possible to pair
                                             // up
        return -1;

    int i = 0;
    int j = 0;

    // now we are calculating the max window size which can be deleted
    while (i < s.size())
    {
        if (s[i] == 'a')
            cnt_a--;
        else if (s[i] == 'b')
            cnt_b--;
        else
            cnt_c--;

        // now suppose if any of the count becomes less than k ten we ahve
        // to shrink the window
        while (j <= i && (cnt_a < k || cnt_b < k || cnt_c < k))
        {
            if (s[j] == 'a')
                cnt_a++;
            else if (s[j] == 'b')
                cnt_b++;
            else
                cnt_c++;

            j++;
        }

        maxi = max(maxi, i - j + 1);
        i++;
    }

    return s.size() - maxi;
}
int main()
{

    return 0;
}