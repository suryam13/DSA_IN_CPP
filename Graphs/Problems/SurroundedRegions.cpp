#include <bits/stdc++.h>
using namespace std;

// LC :130 Sheet

class Solution
{
public:
    void solve(vector<vector<char>> &board)
    {

        // in this what i have been asked is that i have to convert the 0's into X's only if a 0 is not somehow
        // connected to a 0 which is on the boundary

        // what i can do is perform a multisource bfs from sources been the ones starting from boundary 0's
        // this can be done through a normal bfs or dfs too

        // TC:Lets suppose at worst case all cells are O's so in total 4 x O(mxn) =>O(mxn)
        vector<vector<int>> dirs{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) // means a boundary
                {
                    if (board[i][j] == 'O')
                    {
                        visited[i][j] = 1;
                        q.push({i, j});
                    }
                }
            }
        }

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

                    if (x_ >= 0 && x_ < m && y_ >= 0 && y_ < n && !visited[x_][y_] && board[x_][y_] == 'O')
                    {
                        q.push({x_, y_});
                        visited[x_][y_] = 1;
                    }
                }
            }
        }

        // now check which zeroes are visited if yes then they are attached to boundary

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'O' && !visited[i][j])
                    board[i][j] = 'X';
            }
        }
    }
};
int main()
{

    return 0;
}