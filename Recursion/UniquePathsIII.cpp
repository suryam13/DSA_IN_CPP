#include <bits/stdc++.h>
using namespace std;
/*
  T.C. O(3^mxn) because at one point u will be having only 3 options because u
  cant again go back from where u came so u have 3 options at each cells
  S.C O(k) non obstacles
  */
int ans = 0;

void solve(vector<vector<int>> &mat, int m, int n, int row, int col,
           int count)
{
    if (row >= m || col >= n || row < 0 || col < 0 || mat[row][col] == -1)
        return;

    if (mat[row][col] == 2)
    {
        if (count == 0) // means has gone through all the valid cells
            ans++;

        return;
    }

    mat[row][col] = -1; // marking so that it doesnt come again to this
                        // throughout this particular path

    // going right
    solve(mat, m, n, row, col + 1, count - 1);

    // going left

    solve(mat, m, n, row, col - 1, count - 1);

    // going up

    solve(mat, m, n, row - 1, col, count - 1);

    // going down

    solve(mat, m, n, row + 1, col, count - 1);

    // marking unvisited again
    mat[row][col] = 0;
}
int uniquePathsIII(vector<vector<int>> &grid)
{

    int m = grid.size();
    int n = grid[0].size();
    int row = 0;   // row to start(1)
    int col = 0;   // col to start(1)
    int count = 0; // no of non-obstacles

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 0)
                count++;

            else if (grid[i][j] == 1)
            {
                row = i;
                col = j; // finding the stating point(1)
            }
        }
    }

    solve(grid, m, n, row, col,
          count + 1); //+1 because we have to consider the starting point as
                      // that is also a non obstacle,not necessary that
                      // start would always be 0,0
    return ans;
}

int main()
{

    return 0;
}