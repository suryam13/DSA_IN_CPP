#include <bits/stdc++.h>
using namespace std;

// GFG
int helper(vector<int> &height, int i, vector<int> &dp)
{

    if (i == 0)
        return 0;

    if (dp[i] != -1)
        return dp[i]; // overlapping subproblems

    int left = INT_MAX, right = INT_MAX;

    // for n-1
    if (i - 1 >= 0)
        left = abs(height[i] - height[i - 1]) + helper(height, i - 1, dp);

    // for n-2
    if (i - 2 >= 0)
        right = abs(height[i] - height[i - 2]) + helper(height, i - 2, dp);

    return dp[i] = min(left, right);
}

int minCost(vector<int> &height)
{

    int n = height.size();

    // in this got to know that there re repeating sub problems
    /*  we want the minimum cost and options are either we can take n-1 or n-2
        so we calculate and store the minimum cost required to reach for a particular idx
                     5
                 4        3
              3    2   2   1

    so here f(3) f(2) are called multiple times so why not memoize i
    */

    vector<int> dp(n + 1, -1);

    // tabulation
    // look at the base case and use it as start
    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        // 1 step
        int left = dp[i - 1] + abs(height[i] - height[i - 1]);

        // 2 step
        int right = INT_MAX;
        if (i > 1)
            right = dp[i - 2] + abs(height[i] - height[i - 2]);

        dp[i] = min(left, right);
    }

    return dp[n - 1];
}

int main()
{

    return 0;
}