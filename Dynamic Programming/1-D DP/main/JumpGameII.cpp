#include <bits/stdc++.h>
using namespace std;

// Memoization
int helper(vector<int> &nums, int i, vector<int> &dp)
{
    if (i == nums.size() - 1)
        return 0;

    if (i >= nums.size())
        return INT_MAX;

    if (dp[i] != -1)
        return dp[i];

    int mini = INT_MAX;

    for (int ind = i; ind < i + nums[i] && ind < nums.size(); ind++)
    {

        int get = helper(nums, ind + 1, dp);

        if (get == INT_MAX)
            continue;

        int val = 1 + get;

        mini = min(mini, val);
    }

    return dp[i] = mini;
}
int jump(vector<int> &nums)
{

    // MEMOIZATION

    int n = nums.size();
    vector<int> dp(n, -1);
    return helper(nums, 0, dp);
}

// Tabulation
int jump(vector<int> &nums)
{

    // Tabulation

    int n = nums.size();
    vector<int> dp(n + 1, INT_MAX);
    dp[n - 1] = 0;

    for (int i = n - 2; i >= 0; i--)
    {
        int mini = INT_MAX;
        for (int ind = i; ind < i + nums[i] && ind < nums.size(); ind++)
        {

            int get = dp[ind + 1];

            if (get == INT_MAX)
                continue;

            int val = 1 + get;

            mini = min(mini, val);
        }

        dp[i] = mini;
    }

    return dp[0];
}

// BFS
int jump(vector<int> &nums)
{

    queue<int> q;
    q.push(0); // 0th idx
    int steps = 0;

    unordered_set<int> visited;

    while (!q.empty())
    {
        int size = q.size();

        while (size--)
        {
            int i = q.front();
            q.pop();

            if (i == nums.size() - 1)
                return steps;

            if (visited.count(i))
                continue;

            for (int ind = i + 1; ind <= i + nums[i] && ind < nums.size(); ind++)
            {
                q.push(ind); // means now am at this idx after the jump
                visited.insert(i);
            }
        }
        steps++;
    }

    return -1;
}

int main()
{

    return 0;
}