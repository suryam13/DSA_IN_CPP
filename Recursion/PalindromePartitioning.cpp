#include <bits/stdc++.h>
using namespace std;
/*
  T.C.O(2^n)xn for palindrome
  S.C.stack space-O(n) auxillary-same as tc
  */
vector<vector<string>> ans;

bool isPali(string &s, int i, int j)
{
    while (i < j)
    {
        if (s[i] != s[j])
            return false;

        i++;
        j--;
    }
    return true;
}

void solve(string &s, vector<string> &temp, int ind)
{
    if (ind >= s.size()) // means have reached the end
    {
        ans.push_back(temp);
        return;
    }

    for (int i = ind; i < s.size(); i++)
    {
        if (isPali(s, ind, i))
        {
            temp.push_back(s.substr(ind, i - ind + 1));
            solve(s, temp, i + 1); // means ith position tak check kar liya
                                   // hai iske agge se partition dekho
            temp.pop_back();
        }
    }
}
vector<vector<string>> partition(string s)
{
    vector<string> temp;

    solve(s, temp, 0);
    return ans;
}
int main()
{

    return 0;
}