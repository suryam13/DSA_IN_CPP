#include<bits/stdc++.h>
using namespace std;

//LC - HARD

//Linear Search with DP - memoization
int helper(vector<vector<int>>& events, int k ,int i, vector<vector<int>> &dp)
    {
        if(i>=events.size() || k==0)
        return 0;

        if(dp[i][k]!=-1) 
        return dp[i][k];

        vector<int> temp = {events[i][1],INT_MAX,INT_MAX};

        int newIdx = i+1;

        for(;newIdx<events.size();newIdx++)
        {
            if(events[newIdx][0] > events[i][1])
            break;
        }

        int take = events[i][2] + helper(events,k-1,newIdx,dp);

        int not_take = helper(events,k,i+1,dp);

        return dp[i][k] = max(take,not_take);
    }
    int maxValue(vector<vector<int>>& events, int k) {

        sort(events.begin(),events.end());
        int n = events.size();

        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));

        return helper(events,k,0,dp);
    }

//Linear Search with DP - tabulation
int maxValue(vector<vector<int>>& events, int k) {

        sort(events.begin(),events.end());
        int n = events.size();
        

        //Tabulation
        vector<vector<int>> dp(n+1,vector<int>(k+1,0));
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=1;j<=k;j++)
            {
                vector<int> temp = {events[i][1],INT_MAX,INT_MAX};

                int newIdx = i+1;

                for(;newIdx<n;newIdx++)
                {
                    if(events[newIdx][0] > events[i][1])
                    break;
                }

                int take = events[i][2] + dp[newIdx][j-1];

                int not_take = dp[i+1][j];

                dp[i][j] = max(take,not_take);
            }
        }

        return dp[0][k];
}


//Binary Search with DP - memoization
class Solution {
public:

    int helper(vector<vector<int>>& events, int k ,int i, vector<vector<int>> &dp)
    {
        if(i>=events.size() || k==0)
        return 0;

        if(dp[i][k]!=-1) 
        return dp[i][k];

        vector<int> temp = {events[i][1],INT_MAX,INT_MAX};

        int newIdx = upper_bound(events.begin()+i+1,events.end(),temp) - events.begin();
        //gives just greater value idx..when we do iterator - iterator we directly get the idx

        int take = events[i][2] + helper(events,k-1,newIdx,dp);

        int not_take = helper(events,k,i+1,dp);

        return dp[i][k] = max(take,not_take);
    }
    int maxValue(vector<vector<int>>& events, int k) {

        sort(events.begin(),events.end());
        int n = events.size();

        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));

        return helper(events,k,0,dp);
    }
};


//Binary Search with DP - tabulation (most optimised)
class Solution {
public:

    int helper(vector<vector<int>>& events, int k ,int i, vector<vector<int>> &dp)
    {
        if(i>=events.size() || k==0)
        return 0;

        if(dp[i][k]!=-1) 
        return dp[i][k];

        vector<int> temp = {events[i][1],INT_MAX,INT_MAX};

        int newIdx = upper_bound(events.begin()+i+1,events.end(),temp) - events.begin();
        //gives just greater value idx..when we do iterator - iterator we directly get the idx

        int take = events[i][2] + helper(events,k-1,newIdx,dp);

        int not_take = helper(events,k,i+1,dp);

        return dp[i][k] = max(take,not_take);
    }
    int maxValue(vector<vector<int>>& events, int k) {

        sort(events.begin(),events.end());
        int n = events.size();
        

        //Tabulation
        vector<vector<int>> dp(n+1,vector<int>(k+1,0));
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=1;j<=k;j++)
            {
                vector<int> temp = {events[i][1],INT_MAX,INT_MAX};

                int newIdx = upper_bound(events.begin()+i+1,events.end(),temp) - events.begin();
                //gives just greater value idx..when we do iterator - iterator we directly get the idx

                int take = events[i][2] + dp[newIdx][j-1];

                int not_take = dp[i+1][j];

                dp[i][j] = max(take,not_take);
            }
        }

        return dp[0][k];
    }
};

 int main()
{
    
    return 0;
}