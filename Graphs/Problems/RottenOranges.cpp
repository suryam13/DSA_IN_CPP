#include <bits/stdc++.h>
using namespace std;

// LC-994 : Sheet
// TC : O(4*(mxn) + mxn ) +O (mxn)(fro counting fresh and rotten oranges in matrix) => O(mxn)

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {

        // Question of multisource BFS as there could be multiple rotten oranges and at they would start
        // rotting the oranges cocurrently

        vector<vector<int>> dirs{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        int mins = 0, fresh = 0;
        queue<pair<int, int>> q;
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                    fresh++;

                else if (grid[i][j] == 2)
                    q.push({i, j}); // for multisource BFS
            }
        }

        if (fresh == 0)
            return 0; // no fresh to get rotten

        while (!q.empty())
        {
            int size = q.size();

            while (size--)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for (auto &dir : dirs)
                {
                    int x_ = x + dir[0];
                    int y_ = y + dir[1];

                    if (x_ >= 0 && x_ < m && y_ >= 0 && y_ < n && grid[x_][y_] == 1)
                    {
                        q.push({x_, y_});
                        grid[x_][y_] = 2; // make it rotten so that it doesnt gets visited again
                        fresh--;
                    }
                }
            }

            if (!q.empty()) // if the q is empty mins all possible oranges are been rotten no need of extra minute
                mins++;
        }

        return fresh == 0 ? mins : -1;
    }
};
int main()
{

    return 0;
}