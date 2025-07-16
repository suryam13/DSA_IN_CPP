#include <bits/stdc++.h>
using namespace std;


//GFG Sheet
typedef long long ll;

int helper(vector<int> &arr, int i, int sum, int target, vector<vector<int>> &dp)
{
    if (i == arr.size())
        return sum == target ? 1 : 0;

    if (sum > target)
        return 0;

    if (dp[i][sum] != -1)
        return dp[i][sum];

    int take = helper(arr, i + 1, sum + arr[i], target, dp);

    int not_take = helper(arr, i + 1, sum, target, dp);

    return dp[i][sum] = take + not_take;
}

int countPartitions(vector<int> &arr, int d)
{

    /*
      find subsets where s1 - s2 = d
      => (total-s2) - s2 =d
      => total - 2s2 = d
      => s2 = total - d / 2

      so in short we have to find the subsets with sum s2,same as count subsets with sum k


    */
    int n = arr.size();

    ll total = accumulate(arr.begin(), arr.end(), 0);

    if (total - d < 0 || ((total - d) & 1))
        return 0; // since odd so 0 becuase 11/2 = 5 which is not correct
    // according to question
    // total - d >=0 because lets suppose if total is 10 and d is 11 so it would be -1
    // but how can the subset sum of S2 be negative when all of the nums in the array
    // are +ve

    ll s2 = (total - d) / 2;

    vector<vector<int>> dp(n, vector<int>(s2 + 1, -1));

    return helper(arr, 0, 0, s2, dp);
}

int main()
{

    return 0;
}