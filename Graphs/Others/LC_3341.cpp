#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> P;

int minTimeToReach(vector<vector<int>> &moveTime)
{

    vector<vector<int>> dirs{{0, 1}, {1, 0}, {-1, 0}, {0, -1}}; // Right Down Up Left

    // Dijkstra on Matrix
    int n = moveTime.size();
    int m = moveTime[0].size();

    vector<vector<int>> costy(n, vector<int>(m, INT_MAX));

    priority_queue<P, vector<P>, greater<P>> pq; // cost,{co-ordinates}
    pq.push({0, {0, 0}});                        // satrting from origin
    costy[0][0] = 0;

    while (!pq.empty())
    {
        auto topy = pq.top();
        pq.pop();
        int cost = topy.first;
        int x = topy.second.first;
        int y = topy.second.second;

        if (x == n - 1 && y == m - 1)
            return costy[n - 1][m - 1];

        for (auto &dir : dirs) // iterate on every direction and check if feasible
        {

            int x_ = x + dir[0];
            int y_ = y + dir[1];
            // new co-ordinates

            if (x_ < 0 || x_ >= n || y_ < 0 || y_ >= m) // constraint check
                continue;

            int costToGo = moveTime[x_][y_];

            if (cost >= costToGo) // means we can safely move onto
            {
                if (cost + 1 < costy[x_][y_])
                {
                    costy[x_][y_] = cost + 1;
                    pq.push({costy[x_][y_], {x_, y_}});
                }
            }

            else
            {
                // have to add the required cost to move
                int req = costToGo - cost;

                if (cost + req + 1 < costy[x_][y_])
                {
                    costy[x_][y_] = cost + req + 1;
                    pq.push({costy[x_][y_], {x_, y_}});
                }
            }
        }
    }

    return costy[n - 1][m - 1];
}
int main()
{

    return 0;
}