#include <bits/stdc++.h>
using namespace std;

// GFG SHEET

// MEMOIZATION
// Generally the tc in dp is same as of the states required for computation * tasks done per call
bool helper(vector<int> &arr, int sum, int target, int i, vector<vector<int>> &dp)
{
    if (sum == target)
        return true;

    if (i >= arr.size() || sum > target)
        return false;

    if (dp[i][sum] != -1)
        return dp[i][sum];

    // take
    if (helper(arr, sum + arr[i], target, i + 1, dp))
        return true;

    // not take
    if (helper(arr, sum, target, i + 1, dp))
        return true;

    return dp[i][sum] = false;
}

bool isSubsetSum(vector<int> &arr, int sum)
{

    /*
    Time Complexity :
    Before memoization : O(2^n)  as for every i we had two choices take or not take

    After memoization : O(rows*cols) => O(n*sum(target))

    Space complexity : O(rows * cols) + O(n) (stack space/auxillary space)
    */
    int cal = 0;
    int n = arr.size();

    // at max the target can be the max number of cols needed,because we are returning
    // false as soon as it reaches higher than the target so need of stroing that

    vector<vector<int>> dp(n, vector<int>(sum, -1));

    return helper(arr, cal, sum, 0, dp);
}


// TABULATION


    // i wrote the recursion from 0 to N so trying to write the tabulation from n to 0

    // in recursion i was predicting looking at whether at this particular idx
    // with sum is it possible to reach the target, so when converting into tabulation
    // i need to know the next i+1 output for each example

    //by doing so we cn replicate the same thing by just looking at the recursive code

bool isSubsetSum(vector<int> &arr, int sum)
{

    // Tabulation Approach
    int n = arr.size();

    // dp[i][j] states that if at this index we have this sum then what would
    // be the output if i take this current value or not_take
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

    //base case as when lets suppsose my idx is at 'n' and i have all the elments explored than if i have this sum then it is true state
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
            if (arr[i] + j <= sum)
                take = dp[i + 1][arr[i] + j];
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

//SPACE OPTIMISED : 
//we only want two rows one for the reference i.e the next row and one the current which we are filling values that would be used for the other in next iteration

int main()
{

    return 0;
}