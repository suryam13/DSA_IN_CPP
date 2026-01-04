#include <bits/stdc++.h>
using namespace std;
// LC-890

vector<string> findAndReplacePattern(vector<string> &words, string pattern)
{

    vector<string> v;
    map<char, char> patternmapy;

    char ch = 'a';
    for (int i = 0; i < pattern.size(); i++)
    {
        if (patternmapy.find(pattern[i]) == patternmapy.end())
        {
            patternmapy[pattern[i]] = ch;
            ch++;
        }
    }

    map<int, int> wordmapy;

    ch = 'a';
    for (int i = 0; i < words.size(); i++)
    {
        string s = words[i];
        ch = 'a';
        wordmapy.clear();

        for (int i = 0; i < s.size(); i++)
        {
            if (wordmapy.find(s[i]) == wordmapy.end())
            {
                wordmapy[s[i]] = ch;
                ch++;
            }
        }

        int temp = -1;
        for (int i = 0; i < s.size(); i++)
        {
            if (wordmapy[s[i]] != patternmapy[pattern[i]])
            {
                temp = 0;
                break;
            }
        }

        if (temp == -1)
        {
            v.push_back(s);
        }
    }

    return v;
}

void mapping(string &s)
{
    char temp[300];
    char ch = 'a';

    for (auto it : s)
    {
        if (temp[it] == 0)
        {
            temp[it] = ch;
            ch++;
        }
    }

    // now saving as per the mapped characters
    for (int i = 0; i < s.size(); i++)
    {
        s[i] = temp[s[i]];
    }
}
vector<string> findAndReplacePattern(vector<string> &words, string pattern)
{

    vector<string> v;

    mapping(pattern);

    // now mapping the word and comparing them

    for (auto it : words)
    {
        string sss = it;
        mapping(sss);

        if (sss == pattern)
        {
            v.push_back(it);
        }
    }

    return v;
}
int main()
{

    return 0;
}