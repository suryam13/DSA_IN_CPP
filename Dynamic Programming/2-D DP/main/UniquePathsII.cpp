#include <bits/stdc++.h>
using namespace std;

//LC 63 Sheet
//Memoization
class Solution
{
public:
    int helper(vector<vector<int>> &grid, int i, int j, int m, int n, vector<vector<int>> &dp)
    {
        if (i == m || j == n || grid[i][j] == 1)
            return 0;

        if (i == m - 1 && j == n - 1)
            return 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        int down = helper(grid, i + 1, j, m, n, dp);

        int right = helper(grid, i, j + 1, m, n, dp);

        return dp[i][j] = down + right;
    }
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return helper(obstacleGrid, 0, 0, m, n, dp);
    }
};

int main()
{

    return 0;
}