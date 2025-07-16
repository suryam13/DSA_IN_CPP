#include <bits/stdc++.h>
using namespace std;

// SHEET LC 516
class Solution
{
public:
    int helper(int i, int j, string &s, int n, vector<vector<int>> &dp)
    {

        if (i > j)
            return 0;

        if (i == j)
            return 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == s[j])
            return dp[i][j] = 2 + helper(i + 1, j - 1, s, n, dp);

        else
            return dp[i][j] = max(helper(i, j - 1, s, n, dp), helper(i + 1, j, s, n, dp));
    }

    int longestPalindromeSubseq(string s)
    {

        int n = s.length();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return helper(0, n - 1, s, n, dp);
    }
};





//Method 2

class Solution
{
public:
    int helper(string &text1, string &text2, int i, int j, vector<vector<int>> &dp)
    {
        if (i == text1.size() || j == text2.size())
            return 0; // as no char can be compared now amongst two strings

        if (dp[i][j] != -1)
            return dp[i][j];

        if (text1[i] == text2[j])                              // means they are same so 1
            return 1 + helper(text1, text2, i + 1, j + 1, dp); // move both the indices forward

        // not equal so check by moving both the indices one by one

        int moveI = helper(text1, text2, i + 1, j, dp);

        int moveJ = helper(text1, text2, i, j + 1, dp);

        return dp[i][j] = max(moveI, moveJ);
    }

    int longestPalindromeSubseq(string s)
    {

        int n = s.length();
        string t(s);
        reverse(s.begin(), s.end());
        vector<vector<int>> dp(n, vector<int>(n, -1));

        // using the LCSubSeq logic and calling it for s and rev(s)

        return helper(s, t, 0, 0, dp);
    }
};
int main()
{

    return 0;
}