#include <bits/stdc++.h>
using namespace std;

//GFG : Sheet
class Solution
{
public:
    vector<vector<int>> dirs{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    void dfs(vector<vector<int>> &grid, vector<vector<int>> &dummy, vector<vector<bool>> &visited, int x, int y, int ref1, int ref2, int m, int n)
    {
        visited[x][y] = true;
        dummy.push_back({ref1 - x, ref2 - y});
        for (auto &dir : dirs)
        {
            int x_ = x + dir[0];
            int y_ = y + dir[1];

            if (x_ >= 0 && x_ < m && y_ >= 0 && y_ < n && !visited[x_][y_] && grid[x_][y_] == 1)
            {
                dfs(grid, dummy, visited, x_, y_, ref1, ref2, m, n);
            }
        }
    }

    int countDistinctIslands(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        // in order to find the pattern of similiar paatterns we can consider the starting co-ordinate as reference
        //  and keep subtracting the consequent ones

        set<vector<vector<int>>> st;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j] && grid[i][j] == 1)
                {
                    vector<vector<int>> dummy;
                    dfs(grid, dummy, visited, i, j, i, j, m, n);
                    st.insert(dummy);
                }
            }
        }

        return st.size();
    }
};

int main()
{

    return 0;
}