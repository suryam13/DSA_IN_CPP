#include <bits/stdc++.h>
using namespace std;

// LC 416 Sheet
// Memoization

class Solution
{
public:
    typedef long long ll;

    bool helper(vector<int> &nums, int i, ll dummy, ll sum, vector<vector<int>> &dp)
    {
        if (dummy == sum)
            return true;

        if (i == nums.size() || dummy > sum)
            return false;

        if (dp[i][dummy] != -1)
            return dp[i][dummy];

        // take
        if (helper(nums, i + 1, dummy + nums[i], sum, dp))
            return dp[i][dummy] = true;

        // not take
        if (helper(nums, i + 1, dummy, sum, dp))
            return dp[i][dummy] = true;

        return dp[i][dummy] = false;
    }

    bool canPartition(vector<int> &nums)
    {
        // equal subset means there should exist a subsequence which is half of the total sum
        // of the nums

        /*
            How to think of memoization ?
            here we have two changing parameters i and dummy
            -> i can range form 0 to n
            -> dummy can range from 0 to half+1;

            the state defines that is it possible to reach target from [i][dummy] : index i with current sum dummy
         */
        int n = nums.size();
        ll sum = accumulate(nums.begin(), nums.end(), 0);
        ll half = sum / 2;

        if (sum & 1)
            return false;

        vector<vector<int>> dp(n, vector<int>(half + 1, -1));

        return helper(nums, 0, 0, sum / 2, dp);
    }
};

// Tabulation
class Solution
{
public:
    typedef long long ll;

    bool canPartition(vector<int> &nums)
    {

        // Tabulation
        int n = nums.size();
        ll sum = accumulate(nums.begin(), nums.end(), 0);
        ll half = sum / 2;

        if (sum & 1)
            return false;

        vector<vector<bool>> dp(n + 1, vector<bool>(half + 1, false));

        // base case as when lets suppsose my idx is at 'n' and i have all the elments explored than if i have this sum then it is true state
        dp[n][half] = true;

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j <= half; j++)
            {
                // j represents that if have this current sum accumulated now then what?
                // what would happen if we take the cuurent i index element and what
                // if we not_take

                // take
                bool take = false;
                // check if we can actually take it or not as it shouldnt exceed the sum
                // on addition,else out of index bound as our limit is only uptill sum to store in dp
                if (nums[i] + j <= half)
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

        // check at the 0 0 cell which defines that what if i took this idx value and
        // got the target or what if i didnt took this cell and got the target
        // that would be stored in this,if by any means by taking the target or not taking
        // if true then i can reach the target else not
        return dp[0][0];
    }
};

int main()
{

    return 0;
}