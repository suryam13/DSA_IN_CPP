#include <bits/stdc++.h>
using namespace std;

// GFG Sheet

// Memoization :
// TC : O(n*target)
// SC : O(n*target) + O(n) stack space

int helper(vector<int> &arr, int i, int sum, int target, vector<vector<int>> &dp)
{
    if (i == arr.size())
        return sum == target ? 1 : 0;

    if (sum > target)
        return 0;

    if (dp[i][sum] != -1)
        return dp[i][sum];

    int take = helper(arr, i + 1, sum + arr[i], target, dp);

    int not_take = helper(arr, i + 1, sum, target, dp);

    return dp[i][sum] = take + not_take;
}

int perfectSum(vector<int> &arr, int target)
{

    // MEMOIZATION
    int n = arr.size();
      vector<vector<int>> dp(n,vector<int>(target+1,-1));

      return helper(arr,0,0,target,dp);
}

// Tabulation :
// TC : O(n*target)
// SC : O(n*target) + O(n) stack space

// Tabulation

int perfectSum(vector<int> &arr, int target)
{
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

    // will go from n-1 to 0 as i have written in 0 -> n in the recursive solution

    dp[n][target] = 1; // as per the base case

    // now as this is a 2D DP so have to use two loops
    // dp[i][j] states that at this current idx if jave this much j sum and if i take
    // the ith element or not take the ith elment then what is the count of the target
    // that can be achieved

    // In tabualtion the line of code is same as that of the recursive solution just in
    // place helper(i+1) comes dp[i+1] as we are going backward so it gets stored earlier

    for (int i = n - 1; i >= 0; i--)
    {
        for (int sum = 0; sum <= target; sum++)
        {
            int take = 0;
            if (sum + arr[i] <= target) // as in the recursion
                take = dp[i + 1][sum + arr[i]];
            // check if the sum doesnt get out of bound then only there is a way

            int not_take = dp[i + 1][sum]; // as i the recursion

            dp[i][sum] = take + not_take;
        }
    }

    return dp[0][0];
}

int main()
{

    return 0;
}