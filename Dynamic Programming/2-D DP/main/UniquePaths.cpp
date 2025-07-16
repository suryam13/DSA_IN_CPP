#include <bits/stdc++.h>
using namespace std;

//LC 62 Sheet
// Memoization
class Solution
{
public:
    int helper(vector<vector<int>> &grid, int i, int j, int m, int n, vector<vector<int>> &dp)
    {
        if (i == m || j == n)
            return 0;

        if (i == m - 1 && j == n - 1)
            return 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        int down = helper(grid, i + 1, j, m, n, dp);

        int right = helper(grid, i, j + 1, m, n, dp);

        return dp[i][j] = down + right;
    }
    int uniquePaths(int m, int n)
    {

        vector<vector<int>> dp(m, vector<int>(n, -1));

        vector<vector<int>> grid(m, vector<int>(n, -1));
        // no need of makng grid but still did

        return helper(grid, 0, 0, m, n, dp);
    }
};

// Tabulation
class Solution
{
public:
    int helper(vector<vector<int>> &grid, int i, int j, int m, int n, vector<vector<int>> &dp)
    {
        if (i == m || j == n)
            return 0;

        if (i == m - 1 && j == n - 1)
            return 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        int down = helper(grid, i + 1, j, m, n, dp);

        int right = helper(grid, i, j + 1, m, n, dp);

        return dp[i][j] = down + right;
    }
    int uniquePaths(int m, int n)
    {

        vector<vector<int>> dp(m, vector<int>(n, -1));

        // tabulation

        dp[0][0] = 1;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    continue;
                // skip for the starting cell

                // check how many ways are posiible from left and top to reach this cell
                // as we are doing reverse engineering
                int left = 0, top = 0;

                if (j > 0)
                    left = dp[i][j - 1];

                if (i > 0)
                    top = dp[i - 1][j];

                dp[i][j] = left + top;
            }
        }

        return dp[m - 1][n - 1];
    }
};

// Space Optimised
class Solution
{
public:
    int uniquePaths(int m, int n)
    {

        vector<vector<int>> dp(m, vector<int>(n, -1));

        // tabulation with space optmization :
        // came to know that for particualr cell we just need the left of the cell in a row and for the top just
        // above that from the prvious row we computed entire thing and stored in a temp vector which represents
        // the values for the previous row and keep on updatinf at each cell to make sure it is ready for the next
        // row computations

        vector<int> temp(n, -1);
        temp[0] = 1; // setting the initial value
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    continue;
                // skip for the starting cell as it is been intialised

                int left = 0, top = 0;

                if (j > 0)
                    left = temp[j - 1]; // the just left cell

                if (i > 0)
                    top = temp[j]; // at this time it is representing the just above cell changed at next step

                temp[j] = left + top;
            }
        }

        return temp[n - 1];
    }
};

int main()
{

    return 0;
}