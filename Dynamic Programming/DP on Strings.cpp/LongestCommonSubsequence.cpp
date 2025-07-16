#include <bits/stdc++.h>
using namespace std;

// LC 1143

// Recursion + Memoization
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

    int longestCommonSubsequence(string text1, string text2)
    {

        int m = text1.size();
        int n = text2.size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        // dp[i][j] states that at ith index of text1 and jth index of text2 what is the length of subsequence that
        // can be formed further with this configuration.

        return helper(text1, text2, 0, 0, dp);
    }
};

// Tabulation
int longestCommonSubsequence(string text1, string text2)
{
    int m = text1.size();
    int n = text2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // i and j was moving from 0 to n in recursion
    // so in tabulation they will move backwards

    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (text1[i] == text2[j])
            {                                    // means they are same so 1
                dp[i][j] = 1 + dp[i + 1][j + 1]; // move both the indices forward
                continue;
            }

            // not equal so check by moving both the indices one by one

            int moveI = dp[i + 1][j];

            int moveJ = dp[i][j + 1];

            dp[i][j] = max(moveI, moveJ);
        }
    }

    return dp[0][0];
}

int main()
{

    return 0;
}