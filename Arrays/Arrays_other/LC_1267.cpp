#include <bits/stdc++.h>
using namespace std;
int countServers(vector<vector<int>> &grid)
{

    int cnt = 0;
    vector<int> row(grid.size());
    vector<int> col(grid[0].size());

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == 1)
            {
                row[i]++;
                col[j]++;
            }
        }
    }

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == 1)
            {
                if (row[i] > 1 || col[j] > 1) // means apart from current there are more
                                              // connections which makes it valid
                    cnt++;
            }
        }
    }

    return cnt;
}
int main()
{

    return 0;
}