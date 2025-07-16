#include <bits/stdc++.h>
using namespace std;

// GFG Sheet
int minDifference(vector<int> &nums)
{

    // Below is the tabulation approach for subset sum equals k of gfg
    // over there my dp[i][j] state defines that if we take this sum at this moment is it possible to reach the target

    // so taking that way round
    // if i go at 0th row over there if i access [0][0] i would come to know that if i start from sum=0 whether i would be able
    // to reach the target or not,and if yes then  8-0 = 8 means we can get the value 8 as a subset sum
    // now if on the 0th row if i check sum 4 means starting from 0th row having sum 4 can i reach the target so over there if
    // it comes true in table means 8-4 = 4 sum is possible to generate through the subsets

    // so in this i would generate the subsets to achieve the total sum of the array and would check what all values are possible
    // to generate using the 0th row

    // Tabulation Approach
    int n = nums.size();

    long long sum = accumulate(nums.begin(), nums.end(), 0);

    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

    dp[n][sum] = true;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j <= sum; j++)
        {
            // j represents the if have this current sum then what?
            // what would happen if we take the cuurent i index element and what
            // if we not_take

            // take
            bool take = false;
            // check if we can actually take it or not as it shouldnt exceed the sum
            // on addition else out of index bound
            if (nums[i] + j <= sum)
                take = dp[i + 1][nums[i] + j];
            // check what would have been the output if i took this path as the resuly for
            // this path is stored in the i+1
            // as dp[i][j] states that if at this index we have this sum then what would
            // be the output

            bool not_take = dp[i + 1][j];

            dp[i][j] = take || not_take;
            // if any of this returns true then achievable
        }
    }

    // traversing on 0th row of DP to find out which values are possible to get
    long long mini = INT_MAX;

    // because the best of 14 sum is to get 7 so that 7- (14-7)=0 so looping till half
    for (int i = 0; i <= sum / 2; i++)
    {
        if (dp[0][i] == false)
            continue; // as this value is not possible to make

        int val = sum - i;
        mini = min(mini, abs(val - (sum - val)));
    }

    return mini;
}

int main()
{

    return 0;
}