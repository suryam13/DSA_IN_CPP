#include <bits/stdc++.h>
using namespace std;

//LC 198 Sheet

    // Memoization
    int helper(vector<int> &nums, int i, vector<int> &dp)
    {

        if (i >= nums.size())
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int option1 = 0 + helper(nums, i + 1, dp); // not considering the current one

        int option2 = nums[i] + helper(nums, i + 2, dp); // considering the current one and skipping the next

        return dp[i] = max(option1, option2);
    }
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, -1);
        return helper(nums, 0, dp);
    }


    //Tabulation (Bottom-Up)
    int rob(vector<int>& nums) {

        //Tabulation (Bottom-Up)
        int n = nums.size();
        vector<int> dp(n,-1);

        dp[0]=nums[0];
        //dp[i] state represents the max value possible at ith index by tring out all combinations

        for(int i=1;i<n;i++)
        {
            int take = nums[i];

            if(i>1)
            take+=dp[i-2]; //because i cant take the adjacent one now as i have taken the current 

            int not_take = dp[i-1];

            dp[i]=max(take,not_take);
        }

        return dp[n-1];
    }



    //Tabulation (Bottom-Up) with space optimisation
    int rob(vector<int>& nums) {

        //Tabulation (Bottom-Up) with space optimisation
        int n = nums.size();

        if(n==1)
        return nums[0];

        int prev2 = 0;
        int prev1 = nums[0];
        int curr;
        for(int i=1;i<n;i++)
        {
            int take = nums[i];

            if(i>1)
            take+=prev2; //because i cant take the adjacent one now as i have taken the current 

            int not_take = prev1;

            curr=max(take,not_take);

            prev2=prev1;
            prev1=curr;   
        }

        return curr;
    }

int main()
{

    return 0;
}