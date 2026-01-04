#include <bits/stdc++.h>
using namespace std;

/*
Difference between 0/1 knapsack and fractional knapasack

means in fractional u are allowed to even consume the fractional part i.e value/weight and in 0/1 you have to entirely to take or non take
*/

//GFG SHEET 

// MEMOIZATION
//TC : O(NXW)
int helper(vector<int> &val, vector<int> &wt, int W, int i, int currW, vector<vector<int>> &dp)
{
    if (i == val.size())
        return 0;

    if (currW >= W)
        return 0;

    if (dp[i][currW] != -1)
        return dp[i][currW];

    int take = 0;

    if (currW + wt[i] <= W)
        take = val[i] + helper(val, wt, W, i + 1, currW + wt[i], dp);

    int not_take = helper(val, wt, W, i + 1, currW, dp);

    return dp[i][currW] = max(take, not_take);
}

int knapsack(int W, vector<int> &val, vector<int> &wt)
{

    // i have to entirely take a weight or not_take

    int n = val.size();

    vector<vector<int>> dp(n, vector<int>(W + 1, 0));

    return helper(val, wt, W, 0, 0, dp);
}

// TABULATION
int knapsack(int W, vector<int> &val, vector<int> &wt)
{

    // i have to entirely take a weight or not_take

    int n = val.size();

    // tabulation
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // according to base case if i==n so all are 0's so doing that only

    for (int i = n - 1; i >= 0; i--)
    {
        for (int currW = 0; currW <= W; currW++)
        {
            int take = 0;

            if (currW + wt[i] <= W)
                take = val[i] + dp[i + 1][currW + wt[i]];

            int not_take = dp[i + 1][currW];

            dp[i][currW] = max(take, not_take);
        }
    }

    return dp[0][0];
}

int main()
{

    return 0;
}