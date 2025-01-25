#include <bits/stdc++.h>
using namespace std;

// Approach 1 - need of extra isRight check
vector<string> ans;

bool isRight(string &s)
{
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i - 1] == '1' && s[i] == '1')
            return false;
    }
    return true;
}

void solve(string &s, int n)
{
    if (s.size() == n)
    {
        if (isRight(s))
            ans.push_back(s);

        return;
    }

    s.push_back('0'); // do
    solve(s, n);
    s.pop_back(); // undo

    s.push_back('1'); // do
    solve(s, n);
    s.pop_back(); // undo
}
vector<string> generateBinaryStrings(int num)
{

    string s = "";
    solve(s, num);
    return ans;
}

// Approach-2 no need of extra check
vector<string> ans;

void solve(string &s, int n)
{
    if (s.size() == n)
    {

        ans.push_back(s);

        return;
    }

    s.push_back('0'); // do
    solve(s, n);
    s.pop_back(); // undo

    if (s.empty() || s.back() != '1') //handled through this
    {
        s.push_back('1'); // do
        solve(s, n);
        s.pop_back();
    } // undo
}
vector<string> generateBinaryStrings(int num)
{

    string s = "";
    solve(s, num);
    return ans;
}
int main()
{

    return 0;
}