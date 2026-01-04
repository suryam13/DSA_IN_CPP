#include <bits/stdc++.h>
using namespace std;

// GFG Sheet Ninja training

// Memoization (Top-Down)
int helper(vector<vector<int>> &arr, int row, int prev, vector<vector<int>> &dp)
{

    if (row == arr.size())
        return 0;

    if (dp[row][prev] != -1)
        return dp[row][prev];

    int maxi = INT_MIN;

    for (int col = 0; col < 3; col++)
    {
        // as i cant use the same previous column that was been used
        if (col == prev)
            continue;

        int ans = arr[row][col] + helper(arr, row + 1, col, dp);
        // sending the current col as prev as it cannot be used in the just next recursive call

        maxi = max(maxi, ans);
        // we are tracking max answer which we can get from each column in this row
    }

    return dp[row][prev] = maxi;
    // becuase at row 0 we can take all the all emement so ignore would be -1
    // on  assigning to -1 would give runtime error so avoid
}

int maximumPoints(vector<vector<int>> &arr)
{

    int row = arr.size();

    // cols are by default 3

    // state definition :
    // dp[row][prev] states that on this particular idx when this was the prev,what was
    // the answer received so no need to make the calls again

    vector<vector<int>> dp(row, vector<int>(4, -1));
    // generally rows and 3 columns are required for state representation since i
    // have no constraint for the first round if i send the prev as -1 sp  dp[0][-1] would be invalid hence for that
    // takign dp[0][3] to store that particular state result and sending the initial prev as 3,after the initial recursive
    // call dp[1][3] or dp[2][3] all would be -1 only garbage value as they are never used

    return helper(arr, 0, 3, dp);
}


//Tbaulation bottom-up
  int maximumPoints(vector<vector<int>>& arr) {
        
        int row=arr.size();
        
        //bottom up approach
        
        vector<vector<int>> dp(row,vector<int>(3,-1));
        
        dp[0][0] = arr[0][0];
        dp[0][1] = arr[0][1];
        dp[0][2] = arr[0][2];
     
        
        for(int day=1;day<row;day++)
        {
            for(int col=0;col<3;col++)
            {   //col means for this current day i am taking this col so from previous
                //day i cant use this col
                int maxi = 0;
                
                for(int prev=0;prev<3;prev++)
                {
                    if(col==prev) continue;
                    
                    maxi=max(maxi,dp[day-1][prev]);
                }
                
                dp[day][col] = arr[day][col] + maxi; 
                //considering the current day + maxi which is the best answer received from 
                //previous considerations
            }
        }
        
        return max(dp[row-1][0],max(dp[row-1][1],dp[row-1][2]));
        //now taking the max from both the three answers i got 
        
        /*
             space optimised tabulation process
            // Initial values from day 0
            int prev0 = arr[0][0];
            int prev1 = arr[0][1];
            int prev2 = arr[0][2];
        
            for (int day = 1; day < n; day++) {
                int curr0 = arr[day][0] + max(prev1, prev2);
                int curr1 = arr[day][1] + max(prev0, prev2);
                int curr2 = arr[day][2] + max(prev0, prev1);
        
                prev0 = curr0;
                prev1 = curr1;
                prev2 = curr2;
            }
        
            return max({prev0, prev1, prev2});
        
        */
    }
int main()
{

    return 0;
}