#include <bits/stdc++.h>
using namespace std;

// LC-70
//same as fibonaaci series

    int helper(int i, vector<int> &dp)
    {   
        if(i==0 || i==1) return 1;

        if (dp[i] != -1)
           return dp[i]; 
        
        int val1 = helper(i-1,dp);

        int val2 = helper(i-2,dp);

        return dp[i] = val1 + val2;
    }

    int climbStairs(int n) {
        
      int cnt=0;
      vector<int> dp(n+1,-1);
      return  helper(n,dp);
    }

    //For this tabulation is also same as fibonacci series
    //take dp array and set 0 as 1 and 1 as 1 and then copute further dp[i]=dp[i-1]+dp[i-2] 
    //so here the values can be swapped and used with help of variables like curr,prev,prevMost in order to achieve tabulation with space optimization 

    // //Tabulation with space optimization
    // vector<int> dp(n+1,-1);

    // // dp[0]=1;
    // // dp[1]=1;
    // int a = 1; //for 0 step
    // int b = 1; //for 1 step
    // int c;
    
    // for(int i=2;i<=n;i++)
    // {    
    //     // dp[i]=dp[i-1]+dp[i-2]
    //     c=a+b;
    //     a=b;
    //     b=c;
    // }

    // return c;




int main()
{

    return 0;
}