#include <bits/stdc++.h>
using namespace std;
vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> mapy;

    for (auto it : strs)
    {
        string words = it;
        sort(words.begin(), words.end());
        mapy[words].push_back(it);
        // now whichever word will follow the sorted array would map
    }

    vector<vector<string>> ans;
    for (auto it : mapy)
    {
        ans.push_back(it.second);
    }
    return ans;
}
int main()
{

    return 0;
}