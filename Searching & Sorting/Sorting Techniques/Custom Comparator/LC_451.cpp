#include <bits/stdc++.h>
using namespace std;
string frequencySort(string s)
{

    map<char, int> mapy;
    for (auto it : s)
    {
        mapy[it]++;
    }

    auto comp = [&](char a, char b)
    {
        if (mapy[a] == mapy[b])
            return a < b; // if values are same then jisca ascii kam hai woh
                          // woh pehle

        return mapy[a] > mapy[b]; // jiska val zyada woh pehle
    };

    sort(s.begin(), s.end(), comp);
    return s;
}
int main()
{

    return 0;
}