#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string customSortString(string order, string s)
    {

        unordered_map<char, int> mapy;
        int n = order.size();

        for (int i = 0; i < n; i++)
            mapy[order[i]] = i;

        auto comp = [&](char a, char b)
        {
            int idxA = mapy[a];
            int idxB = mapy[b];

            if (idxA < idxB)
                return true;
            return false;
        };

        sort(s.begin(), s.end(), comp);
        return s;
    }
};