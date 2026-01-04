#include <bits/stdc++.h>
using namespace std;

//Sheet LC-322

// Memoization
int helper(vector<int> &coins, int amount, int i, int currAmount, vector<vector<int>> &dp)
{
    if (currAmount == amount)
        return 0;

    if (i == coins.size()) // limit reached and value couldnt be formed so this combination not be possible
        return INT_MAX;

    if (dp[i][currAmount] != -1)
        return dp[i][currAmount];

    int times = amount / coins[i];
    // this is the max number of times this particular coin could be used

    int mini = INT_MAX;

    // start from because also have to check by taking 0 coins
    for (int j = 0; j <= times; j++)
    {
        if (currAmount + (j * coins[i]) > amount) // not possible to take this coins anymore further
            break;

        int value = helper(coins, amount, i + 1, currAmount + (j * coins[i]), dp);

        if (value != INT_MAX)
            value = value + j;

        mini = min(mini, value);
    }

    return dp[i][currAmount] = mini;
}

int coinChange(vector<int> &coins, int amount)
{

    int n = coins.size();

    // MEMOIZATION
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    // dp[i][j] states that at this point of time at this idx and this currAmount what is the minimum coins
    // needed to make the target amount

    int ans = helper(coins, amount, 0, 0, dp);
    return ans == INT_MAX ? -1 : ans;
}


// Tabulation :
int coinChange(vector<int> &coins, int amount)
{

    int n = coins.size();

    // MEMOIZATION
    //  vector<vector<int>> dp(n,vector<int>(amount+1,-1));
    // dp[i][j] states that at this point of time at this idx and this currAmount what is the minimum coins
    // needed to make the target amount

    // int ans = helper(coins,amount,0,0,dp);
    // return  ans == INT_MAX ? -1 : ans;

    // Tabulation
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, INT_MAX));

    dp[n][amount] = 0; // as per the base case in recursive,and everything else at n with any amount would be INT_MAX because target not
    // made after iterating over all the n elements and reaching at the last

    for (int i = n - 1; i >= 0; i--)
    {
        for (int currAmount = 0; currAmount <= amount; currAmount++)
        {

            int times = amount / coins[i];
            // this is the max number of times this particular coin could be used

            int mini = INT_MAX;

            // start from because also have to check by taking 0 coins
            for (int j = 0; j <= times; j++)
            {
                if (currAmount + (j * coins[i]) > amount) // not possible to take this coins anymore further
                    break;

                int value = dp[i + 1][currAmount + (j * coins[i])];

                if (value != INT_MAX)
                    value = value + j;

                mini = min(mini, value);
            }

            dp[i][currAmount] = mini;
        }
    }

    int ans = dp[0][0];
    return ans == INT_MAX ? -1 : ans;
}

int main()
{

    return 0;
}