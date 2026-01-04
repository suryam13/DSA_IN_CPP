#include <bits/stdc++.h>
using namespace std;
long long calculateScore(string s)
{

    // We have to find the just previous mirror idx
    unordered_map<char, vector<int>> mapy;

    long long ans = 0;

    for (int i = 0; i < s.size(); i++)
    {
        // extracting the mirror of the char
        int ch1 = 'z' - s[i]; // suppose s[i] is 'a' so  25

        char final = 'a' + ch1; // a+25-->'z'

        if (mapy.find(final) != mapy.end() && mapy[final].size() != 0) // means char is present as well as a suitable idx
        {

            ans += i - mapy[final].back();
            // as both current and mirror is used so pop
            mapy[final].pop_back();
        }

        else
        {
            // simply push to be used as mirror
            mapy[s[i]].push_back(i);
        }
    }

    return ans;
}
int main()
{

    return 0;
}