#include <bits/stdc++.h>
using namespace std;

// LC-542 Sheet
class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {

        vector<vector<int>> dirs{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        // reverse engineering,we will find how much time it takes to reach a '1' cell from a '0' cell because
        // if go from 1 to 0 then we would have to store double co-ordinate the src and the dest as in what was
        // the position of 1 which is been traversed

        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 0)
                {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        int cnt = 1;

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

                    if (x_ >= 0 && x_ < m && y_ >= 0 && y_ < n && mat[x_][y_] == 1 && dist[x_][y_] == INT_MAX)
                    {
                        dist[x_][y_] = cnt;
                        q.push({x_, y_});
                    }
                }
            }

            cnt++;
        }

        return dist;
    }
};
int main()
{

    return 0;
}