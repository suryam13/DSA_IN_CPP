#include <bits/stdc++.h>
using namespace std;

// SHEET LC 518

//this can also be solved by take and not take approach when skipping go to i+1 without alterning the current sum but when taking dont go to i+1 instead go i as you can again take the current coins[i] and just send take + not_take at every call,if currAmount + coins[i] > target then just call skip call no need to call take and not take

// MEMOIZATION
class Solution
{
public:
    int helper(vector<int> &coins, int amount, int i, int currAmount, vector<vector<int>> &dp)
    {
        if (currAmount == amount)
            return 1;

        if (i == coins.size()) // limit reached and value couldnt be formed so this combination not be possible
            return 0;

        if (dp[i][currAmount] != -1)
            return dp[i][currAmount];

        int times = amount / coins[i];
        // this is the max number of times this particular coin could be used

        int cnt = 0;

        // start from because also have to check by taking 0 coins
        for (int j = 0; j <= times; j++)
        {
            if (currAmount + (j * coins[i]) > amount) // not possible to take this coins anymore further
                break;

            int value = helper(coins, amount, i + 1, currAmount + (j * coins[i]), dp);

            cnt += value; // adding the ways obtained by taking this coins this many times
        }

        return dp[i][currAmount] = cnt;
    }

    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();

        // MEMOIZATION
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        // dp[i][j] states that at this point of time at this idx and this currAmount what is the number of ways to get the
        // target

        int ans = helper(coins, amount, 0, 0, dp);
        return ans;
    }
};

int main()
{

    return 0;
}