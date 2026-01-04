#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string frequencySort(string s)
    {

        int n = s.size();
        unordered_map<char, int> mapy;

        auto comp = [&](char a, char b)
        {
            if (mapy[a] > mapy[b]) // true aaya means pehle parameter ko pehla rakho i.e a
                return true;

            else if (mapy[a] == mapy[b]) //-> doing this to avoid tc with same freq lolo
            {
                // lets say mein lower ascii ko pehle rakhunga
                if (a < b)
                    return true;

                else
                    return false;
            }

            return false; // means frequency are not same and b has higher one so false means a ko baad mein rakho
        };

        for (auto &ch : s)
            mapy[ch]++;

        sort(s.begin(), s.end(), comp);

        return s;
    }
};