#include <bits/stdc++.h>
using namespace std;
// LC - 1091
int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{

    /* directions -> bottom up right left diagonalRightUp diagonalLeftUp diagonalLeftDown diagonalRightDown */
    vector<pair<int, int>> directions({{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {-1, 1}, {-1, -1}, {1, -1}, {1, 1}});

    int m = grid.size();
    int n = grid[0].size();

    // we have a constant cost of moving that is 1 so we will be using simple bfs approach

    if (grid[0][0] == 1) // not able to start
        return -1;

    queue<pair<int, int>> q; // storing the start co-ordinates
    q.push({0, 0});
    grid[0][0] = 1; // marking the current as visited by inserting 1 so that it doesnt roll back
    int level = 0;

    while (!q.empty())
    {
        int size = q.size();

        while (size--)
        {
            auto topy = q.front();
            q.pop();

            int x = topy.first;
            int y = topy.second;

            if (x == m - 1 && y == n - 1) // mean we have reached the end so please return level + 1
                // means we have taken that many steps
                return level + 1;

            // iterate over all the possible 8 directions to check where we can take the next step
            for (auto &dir : directions)
            {
                int x_ = x + dir.first;
                int y_ = y + dir.second;

                if (x_ >= 0 && x_ < m && y_ < n && y_ >= 0 && grid[x_][y_] == 0) // then can move
                {
                    q.push({x_, y_});
                    grid[x_][y_] = 1; // mark
                }
            }
        }
        level++;
    }
    return -1; // no valid path to reach end
}
int main()
{

    return 0;
}