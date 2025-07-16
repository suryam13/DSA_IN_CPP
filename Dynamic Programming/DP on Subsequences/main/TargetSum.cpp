#include <bits/stdc++.h>
using namespace std;

//LC 494 Sheet
// Memoization
class Solution
{
public:
    int helper(vector<int> &nums, int i, int target, int sum, map<pair<int, int>, int> &dp)
    {
        if (i == nums.size())
            return sum == target; // if equal then 1 way else 0

        if (dp.count({i, sum}))
            return dp[{i, sum}];
        int posi = helper(nums, i + 1, target, sum + nums[i], dp);

        int negi = helper(nums, i + 1, target, sum - nums[i], dp);

        return dp[{i, sum}] = posi + negi;
    }

    int findTargetSumWays(vector<int> &nums, int target)
    {

        int n = nums.size();

        // as there could be -ve sum as well so for that map
        map<pair<int, int>, int> dp;

        return helper(nums, 0, target, 0, dp);
    }
};

// Tabulation
int findTargetSumWays(vector<int> &nums, int target)
{

    int n = nums.size();

    int sum = accumulate(nums.begin(), nums.end(), 0);

    // as there could be -ve sum as well so for that map
    map<pair<int, int>, int> dp;

    // return helper(nums,0,target,0,dp);

    // Tabulation

    dp[{n, target}] = 1;

    for (int i = n - 1; i >= 0; i--)
    {
        // at worst case where all the signs are positive or at worst when all are negative
        for (int j = -sum; j <= sum; j++)
        {
            int posi = dp[{i + 1, j + nums[i]}];

            int negi = dp[{i + 1, j - nums[i]}];

            dp[{i, j}] = posi + negi;
        }
    }

    return dp[{0, 0}];
}

int main()
{

    return 0;
}