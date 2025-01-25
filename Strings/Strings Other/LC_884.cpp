#include <bits/stdc++.h>
using namespace std;

vector<string> uncommonFromSentences(string s1, string s2)
{

    unordered_map<string, int> mapy;
    vector<string> ans;

    string s; // to accumulate chars to form string and then clear
    for (auto it : s1)
    {
        if (it ==
            ' ')
        { // store as string is formed then clear to form a new one
            mapy[s]++;
            s.clear();
        }

        else
            s.push_back(it);
    }
    mapy[s]++; // as the last string wont ecounter any space so add it
               // manually

    s.clear();

    for (auto it : s2)
    {
        if (it == ' ')
        {
            mapy[s]++;
            s.clear();
        }

        else
            s.push_back(it);
    }
    mapy[s]++;

    for (auto it : mapy)
    {
        if (it.second == 1)
            ans.push_back(it.first);
    }

    return ans;
}

// Approach 2 using stringstream
vector<string> uncommonFromSentences(string s1, string s2)
{

    vector<string> ans;

    unordered_map<string, int> mapy;

    // use of string stream is that it is used to consider string and
    // excludes spaces by default
    stringstream ss1(s1);
    string dummy;

    while (ss1 >> dummy) // here every time a new word is been sent into the
                         // dummy and then the dummy is reset
        mapy[dummy]++;

    stringstream ss2(s2);

    while (ss2 >> dummy)
        mapy[dummy]++;

    for (auto it : mapy)
    {
        if (it.second == 1) // means it is unique
            ans.push_back(it.first);
    }

    return ans;
}

int main()
{

    return 0;
}