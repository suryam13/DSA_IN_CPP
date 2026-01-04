#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int helper(vector<int> &arr, int i, int k, int n, vector<int> &dp)
    {
        if (i == n)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int submax = 0; // max value in the subarray
        int value = 0;  // total sum of the subarray after multiplying the max value the len of subarray
        long long sum = 0, maxi = 0;

        // we have k options for each index
        for (int j = 1; j <= k; j++)
        {
            if (i + j - 1 >= n)
                break; // means out of bound so cant consider that index

            // i want to have the max in this subarray
            submax = max(submax, arr[i + j - 1]); // figuring out the current idx is max or not

            value = submax * j; // max * length of subarray
            sum = value + helper(arr, i + j, k, n, dp);
            maxi = max(maxi, sum);
        }

        return dp[i] = maxi;
    }

    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        // Memoization
        int n = arr.size();

        // vector<int> dp(n+1,-1);
        // return helper(arr,0,k,n,dp);

        // Tabulation
        // would be writing same as recursive code just in place of helper(i+) would write dp[i+]
        // keep in mind that whenever writing i->n in recursive go from n->i in tabulation
        vector<int> dp(n + 1, -1);

        dp[n] = 0; // same as recursive code (if  i==n then 0)
        for (int i = n - 1; i >= 0; i--)
        {

            int submax = 0; // max value in the subarray
            int value = 0;  // total sum of the subarray after multiplying the max value the len of subarray
            long long sum = 0, maxi = 0;

            // we have k options for each index
            for (int j = 1; j <= k; j++)
            {
                if (i + j - 1 >= n)
                    break; // means out of bound so cant consider that index

                // i want to have the max in this subarray
                submax = max(submax, arr[i + j - 1]); // figuring out the current idx is max or not

                value = submax * j; // max * length of subarray
                sum = value + dp[i + j];
                maxi = max(maxi, sum);
            }

            dp[i] = maxi;
        }

        return dp[0]; // same as the final answer in recursion was stored at 0th position
    }
};

int main()
{

    return 0;
}