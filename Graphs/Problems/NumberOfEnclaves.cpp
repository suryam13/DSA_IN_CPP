#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numEnclaves(vector<vector<int>> &grid)
    {

        vector<vector<int>> dirs{{0, 1}, {1, 0}, {-1, 0}, {0, -1}}; // Right Down Up Left

        // we will think reverse,we just want to find which cannot be reached at the boundary right ? so do
        // one thing count the total number of 1's  which are not boundary (means has to be explored from boundary)
        // and push the boundary co-ordinates to start multisource BFS.

        int cnt = 0;
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // store the boundaries in queue
                if (grid[i][j] == 1)
                {
                    if (i == 0 || j == 0 || i == m - 1 || j == n - 1) // means boundary
                    {
                        q.push({i, j});
                        grid[i][j] = 0;
                    } // mark this as visited so that we dont travel on boundary via any other

                    else
                        cnt++; // need to reach here via boundary
                }
            }
        }

        while (!q.empty())
        {
            auto topy = q.front();
            int x = topy.first;
            int y = topy.second;
            q.pop();

            for (auto &dir : dirs)
            {
                int x_ = x + dir[0];
                int y_ = y + dir[1];

                if (x_ >= 0 && x_ < m && y_ >= 0 && y_ < n && grid[x_][y_] == 1)
                {
                    grid[x_][y_] = 0; // mark as visited,so that we dont come over here via any other src
                    cnt--;            // means this unreached has been reached so decrement the cnt
                    q.push({x_, y_}); // now explore from here
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