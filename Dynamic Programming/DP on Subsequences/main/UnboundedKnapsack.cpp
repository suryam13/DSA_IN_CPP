#include <bits/stdc++.h>
using namespace std;

// SHEET GFG

// MEMOIZATION
//  User function Template for C++

class Solution
{
public:
    int helper(vector<int> &val, vector<int> &wt, int capacity, int i, int currW, vector<vector<int>> &dp)
    {
        if (i == val.size())
            return 0;
        // reached at end so now no more can be considered

        if (currW >= capacity)
            return 0;
        // its ok if i dont write this because still it never arise as i am checking in if condition earlier

        if (dp[i][currW] != -1)
            return dp[i][currW];

        int take = 0;

        // checking because lets suppose i get 0 from base condition but still the current val
        // would be added and would make 4+0 but should not happen as if the case is violated then
        // how can we take the current weight value

        if (currW + wt[i] <= capacity)
            take = val[i] + helper(val, wt, capacity, i, currW + wt[i], dp);

        int not_take = helper(val, wt, capacity, i + 1, currW, dp);

        return dp[i][currW] = max(take, not_take);
    }

    
    int knapSack(vector<int> &val, vector<int> &wt, int capacity)
    {

        // over here it is given that there is infinite supply of items just like minimum no of coins
        // so we can reuse the same weight multiple times

        int n = val.size();

        // TABULATION
        vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

        // according to base case if i==n so all are 0's so doing that only
        // note that u always fill the things in reverse order even the inner loop
        // as i remains on the same index so it needs the earlier computations done
        // in other problems we were doing i+1 so no problems faced but in this
        // the issure got highlighted

        for (int i = n - 1; i >= 0; i--)
        {
            for (int currW = capacity; currW >= 0; currW--)
            {
                int take = 0;

                if (currW + wt[i] <= capacity)
                    take = val[i] + dp[i][currW + wt[i]];

                int not_take = dp[i + 1][currW];

                dp[i][currW] = max(take, not_take);
            }
        }

        return dp[0][0];
    }
};
int main()
{

    return 0;
}