#include <bits/stdc++.h>
using namespace std;

//LC 213 Sheet

// Memoization
class Solution
{
public:
    int helper(vector<int> &nums, int i, vector<int> &dp, int bound)
    {
        if (i == bound)
            return nums[i];
        // means this has to be considered in sum because the adjacent to it i+1 is not taken,if i+1 was taken prior
        // then this call wouldnt have been received we would have gone to 1-2 = -1 i.e out og bound and would
        // eventually return 0

        if (i < bound)
            return 0;
        // as no house is possible

        if (dp[i] != -1)
            return dp[i];

        int take = nums[i] + helper(nums, i - 2, dp, bound);
        // cant take adjacent i-1 so go to i-2

        int not_take = helper(nums, i - 1, dp, bound);
        // havent considered the current so can go to i-1;

        return dp[i] = max(take, not_take);
    }
    int rob(vector<int> &nums)
    {

        // Memoization (top - down)
        // in this we would have to give two seperate recursive calls one excluding the last and
        // one excluding the first because when both handled in 1 case it becomes difficult to
        // memoize

        // i have solved this by going backwards i.e. n-1 and n-2 instead of going forward n+1 and n+2
        // both are correct but try to go backwards as afterwards tabulation (bottom - up) becomes easier
        int n = nums.size();

        if (n == 1)
            return nums[0];

        vector<int> dp1(n, -1); // excluding the last
        vector<int> dp2(n, -1); // excluding the first

        // passing the bound means u are allowed to go back uptill there only,n is the size of array
        //  0 to n-2  ---> last is ignored
        //  1 to n-1  ---> first house is ignored
        return max(helper(nums, n - 2, dp1, 0), helper(nums, n - 1, dp2, 1));
    }
};

// Tabulation (bottom-up) without space optimisation
class Solution
{
public:
    int rob(vector<int> &nums)
    {

        // Tabulation (bottom-up) without space optimisation
        int n = nums.size();

        if (n == 1)
            return nums[0];

        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);

        // CASE 1 : including first house and excluding the last
        // for the 0th house we know that the best possible way is to rob
        dp1[0] = nums[0];
        // dp1[i] represents the best possible answer upto that houses starting from 0

        for (int i = 1; i < n; i++)
        {

            int take = nums[i];

            if (i > 1)
                take += dp1[i - 2]; // only possible when i is greater than 1 else runtime error
            // cant take adjacent i-1 so go to i-2

            int not_take = dp1[i - 1];
            // havent considered the current so can go to i-1;

            dp1[i] = max(take, not_take);
        }

        // CASE 2:excluding first house and including the last
        dp2[1] = nums[1];
        // dp2[i] represents the best possible answer upto that houses starting from 1

        for (int i = 2; i < n; i++)
        {
            int take = nums[i];

            if (i > 2)
                take += dp2[i - 2]; // only possible when i is greater than 2 because 2-2=0 and i cant take the first house
            // cant take adjacent i-1 so go to i-2

            int not_take = dp2[i - 1];
            // havent considered the current so can go to i-1;

            dp2[i] = max(take, not_take);
        }

        return max(dp1[n - 2], dp2[n - 1]);
        // dp1 max value lies in the last idx i.e n-2 because the very last idx is excluded
        // dp2 max value lies in the last idx i.e n-1 because the very first idx is excluded not the last
    }
};

int main()
{

    return 0;
}