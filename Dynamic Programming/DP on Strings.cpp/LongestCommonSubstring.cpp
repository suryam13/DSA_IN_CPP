#include <bits/stdc++.h>
using namespace std;

//SHEET - GFG
int longestCommonSubstr(string &s1, string &s2)
{

    // Tabulation Approach same as subsequence with minoe changes

    int m = s1.size();
    int n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    int maxi = 0;

    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (s1[i] == s2[j])
            {
                // means they are same so 1 + check the previous consecutive cnt else 0
                dp[i][j] = 1 + dp[i + 1][j + 1];
                maxi = max(maxi, dp[i][j]);

                continue;
            }

            // not equal so break the consecutiveness
            // else
            dp[i][j] = 0;
        }
    }

    return maxi;
}

int main()
{

    return 0;
}