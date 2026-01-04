#include <bits/stdc++.h>
using namespace std;

// LC-200 : Sheet
//TC : O(4*(mxn) + mxn ) 
//because every cell you are checking 4 direction so mxn for every cell movement and for each cell 4x(mxn) 
//4 constant for directions check at every call =>  O(mxn)
class Solution
{
public:
    vector<vector<int>> dirs{{0, 1}, {-1, 0}, {1, 0}, {0, -1}};

    void DFS(vector<vector<char>> &grid, int x, int y, int m, int n)
    {
        grid[x][y] = '0';
        for (auto &dir : dirs)
        {
            int x_ = x + dir[0];
            int y_ = y + dir[1];

            if (x_ >= 0 && x_ < m && y_ >= 0 && y_ < n && grid[x_][y_] == '1')
                DFS(grid, x_, y_, m, n);
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {

        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {

                    DFS(grid, i, j, m, n);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
int main()
{

    return 0;
}