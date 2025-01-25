#include <bits/stdc++.h>
using namespace std;
/*
     T.C-max chars in digits is so 4 raise to nx n for traversal
     so O(4^NxN)
     S.C.O(N)
    */
vector<string> ans;

void solve(string &digits, unordered_map<char, string> &mapy, string &dummy,
           int i)
{
    if (dummy.size() >= digits.size())
    {
        ans.push_back(dummy);
        return;
    }

    string ok = mapy[digits[i]]; // retreiving the string

    for (int ind = 0; ind < ok.size(); ind++)
    {
        dummy.push_back(ok[ind]);
        solve(digits, mapy, dummy, i + 1);
        dummy.pop_back();
    }
}

vector<string> letterCombinations(string digits)
{

    // first i will map all the numbers to their specific string

    if (digits.size() == 0)
        return {};

    unordered_map<char, string> mapy;
    mapy['2'] = "abc";
    mapy['3'] = "def";
    mapy['4'] = "ghi";
    mapy['5'] = "jkl";
    mapy['6'] = "mno";
    mapy['7'] = "pqrs";
    mapy['8'] = "tuv";
    mapy['9'] = "wxyz";
    string dummy = "";

    solve(digits, mapy, dummy, 0);

    return ans;
}
int main()
{

    return 0;
}