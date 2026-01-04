#include <bits/stdc++.h>
using namespace std;

// LC 509 SHEET

    //Memoization
    int helper(int n, vector<int> &dp)
    {
        if (n <= 1)
            return n;

        if (dp[n] != -1)
            return dp[n]; // STEP 2 checking whether it has been memoized earlier

        return dp[n] = helper(n - 1, dp) + helper(n - 2, dp); // STEP 3 memoizing
    }

    int fib(int n)
    {

        // starting the numbering from 0th term,1st term .....

        // DP with memoization (top-bottom)  T.C - O(N) S.C. O(N) +O(N) stack space + dp array

        // as there are n numbers so n numbers would be memoized so ne need to explore every time as
        // if dp[n]!=-1 so we are not exploring  hence the maximum depth will only be considered.

        vector<int> dp(n + 1, -1); // DP vector STEP 1

        return helper(n, dp);        
    }

    //Tabulation
   
    // DP with tabulation (bottom-up) T.C -O(N) S.C O(N) dp array
        // here we solve subproblems starting from the smallest
        //  if(n<=1) return n;

        // vector<int> dp(n+1,-1);
        // dp[0]=0;
        // dp[1]=1;

        // for(int i=2;i<=n;i++)
        // {
        //     dp[i]=dp[i-1]+dp[i-2];
        // }

        // return dp[n];


    
    // Tabulation with space optimization
    // T.C. O(N) S.C. O(1)
    //  int a=0;
    //  int b=1;
    //  int newnum;

    // if(n==0)
    // return a;

    // if(n==1)
    // return b;

    // for(int i=2;i<=n;i++)
    // {
    //      newnum=a+b;
    //      a=b;
    //      b=newnum;

    // }

    // return newnum;


int main()
{

    return 0;
}