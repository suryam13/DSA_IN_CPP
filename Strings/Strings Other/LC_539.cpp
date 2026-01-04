#include <bits/stdc++.h>
using namespace std;

int findMinDifference(vector<string> &s)
{

    vector<int> v;

    // converting each entity into minutes
    for (int i = 0; i < s.size(); i++)
    {
        int time = stoi(s[i].substr(0, 2)) * 60 + stoi(s[i].substr(3, 2));
        v.push_back(time);
    }

    int mini = INT_MAX;

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size() - 1; i++)
    {
        int dummy = (v[i + 1] - v[i]);
        mini = min(mini, dummy);
    }

    // as the cycle gets completed we have to check reverse as well
    int alternate = 1440 - v[v.size() - 1] + v[0];
    mini = min(mini, alternate);

    return mini;
}

int main()
{

    return 0;
}