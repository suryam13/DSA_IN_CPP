#include <bits/stdc++.h>
using namespace std;
// LC-242

bool isAnagram(string s, string t)
{

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    int s1 = s.size();
    int s2 = t.size();

    if (s1 != s2)
        return false;

    if (s.compare(t) == 0)
        return true;

    return false;
}

bool isAnagram(string s, string t)
{

    map<char, int> mapy1;
    map<char, int> mapy2;

    for (auto it : s)
    {
        mapy1[it]++;
    }

    for (auto it : t)
    {
        mapy2[it]++;
    }

    if (mapy1 == mapy2)
        return true;

    else
        return false;
}

bool isAnagram(string s, string t)
{

    int ch[300] = {0};

    for (auto it : s)
    {
        ch[it]++;
    }

    for (auto it : t)
    {
        ch[it]--;
    }

    for (auto it : ch)
    {
        if (it != 0)
            return false;
    }
    return true;
}
int main()
{

    return 0;
}