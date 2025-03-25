#include <bits/stdc++.h>
using namespace std;

// LC-1631
// Dijkstras on matrix
// Ref codestorywithmik
typedef pair<int, pair<int, int>> P;
int minimumEffortPath(vector<vector<int>> &heights)
{
    // directions-4
    vector<vector<int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // right left bottom top

    int rows = heights.size();
    int cols = heights[0].size();

    // this problem is a classic problem on dijkstras on matrix intead of graphs

    // as we created a linear cost array in grpahs,here we would use 2-D matrix to represent costs
    vector<vector<int>> cost(rows, vector<int>(cols, INT_MAX));

    // as we create a min-heap of pair<int,int> which stores cost and vertex we would be storing one more pair
    // inside as we are about to strore the co-ordinates

    priority_queue<P, vector<P>, greater<P>> pq;
    // we are starting from 0,0;

    pq.push({0, {0, 0}}); // cost co-ordinates
    cost[0][0] = 0;       // the minimum cost would be this as we are starting from the 0,0

    while (!pq.empty())
    {
        auto topy = pq.top();
        pq.pop();
        int costy = topy.first;
        int x = topy.second.first;
        int y = topy.second.second; // co=ordinates

        // now checking where we can go from this index
        for (auto &dir : dirs)
        {
            int x_ = x + dir[0];
            int y_ = y + dir[1];

            if (x_ < rows && x_ >= 0 && y_ < cols && y_ >= 0)
            {
                // check the cost now
                int new_cost = abs(heights[x][y] - heights[x_][y_]); // taking the consecutive abs difference

                // i have to go for max consecutive difference
                int maxDiff = max(costy, new_cost); // i have to take the maximum abs diff throughout that path so have to take the max
                // of stored and what got for the new cell in that path

                if (cost[x_][y_] > maxDiff) // then update the cost to get there, as we have got a better cost to get to that cell
                // and push so that we can explore later
                {
                    cost[x_][y_] = maxDiff;
                    pq.push({maxDiff, {x_, y_}});
                }
            }
        }
    }

    return cost[rows - 1][cols - 1];
}
int main()
{

    return 0;
}