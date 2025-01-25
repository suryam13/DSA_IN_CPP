#include <bits/stdc++.h>
using namespace std;

// Approach 1
// TC-O(2^2n*2N) //power because that many combination are been generated and 2N for isValid
// SC-O(2N)//stack space depth and aucillary space for carrying the temp
vector<string> ans; // declaring the ans globally

bool isValid(string &s)
{
    int count = 0;

    for (auto &it : s)
    {
        if (it == '(')
            count++;

        else
            count--;

        if (count < 0)
            return false;
    }
    return count == 0;
}

void solve(string &s, int n)
{
    if (s.size() == 2 * n) // n pairs are there so 2*n
    {
        if (isValid(s))
            ans.push_back(s);

        return;
    }

    // firstly consider '('
    s.push_back('('); // do
    solve(s, n);
    s.pop_back(); // undo

    s.push_back(')'); // do
    solve(s, n);
    s.pop_back(); // undo
}
vector<string> generateParenthesis(int n)
{
    string s = "";
    solve(s, n);
    return ans;
}

// Approach 2
// we got to know that we are unnecessarily checking for the other parenthesis as they are not valid
// so the hack is open<n to be valid close<open and then just remove the check function
/*
 vector<string> ans; // declaring the ans globally

    void solve(string& s, int n, int open, int close) {
        if (s.size() == 2 * n) // n pairs are there so 2*n
        {

            ans.push_back(s);

            return;
        }

        // firstly consider '('
        if (open < n) {
            s.push_back('('); // do
            solve(s, n, open + 1, close);
            s.pop_back(); // undo
        }

        if (close < open) {
            s.push_back(')'); // do
            solve(s, n, open, close + 1);
            s.pop_back(); // undo
        }
    }
    vector<string> generateParenthesis(int n) {
        int open = 0;
        int close = 0;
        string s = "";
        solve(s, n, open, close);
        return ans;
    }
*/
/*
Approach 3-for loop
 vector<string> ans; // declaring the ans globally
    set<string> st;

    bool isValid(string& s) {
        int count = 0;

        for (auto& it : s) {
            if (it == '(')
                count++;

            else
                count--;

            if (count < 0)
                return false;
        }
        return count == 0;
    }

    void solve(string& s, int n, int idx) {

        if (s.length() >= 2 * n && isValid(s)) {
            ans.push_back(s);
            return;
        }

        else if (s.length() >= 2 * n) {
            return;
        }

        for (int i = idx; i < 2 * n; i++) {
            s.push_back('('); // do
            solve(s, n, i + 1);
            s.pop_back();

            s.push_back(')'); // do
            solve(s, n, i + 1);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string s = "";
        solve(s, n, 0);
        return ans;
    }
*/
int main()
{

    return 0;
}