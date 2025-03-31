#include <bits/stdc++.h>
using namespace std;

// HARD PROBLEM

// approach 1 -optimised
class Solution
{
public:
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // direction vector

    vector<int> maxPoints(vector<vector<int>> &grid, vector<int> &queries)
    {

        // Optimised priority queue appraoch

        /*
        We observed that we are iterating over the same cell again and again on different values of queries, for eg all the
        cells which are been visited by 3 would also be definitely visited by 6 also,so optimising it we would sort the queries
        and would not iterate on the ones previously iterated as they would be included in the count
        */
        int m = grid.size();
        int n = grid[0].size();

        // would be also storing the original index of the queries as i have to send the answer in the original manner
        vector<pair<int, int>> sortedQ;

        for (int i = 0; i < queries.size(); i++)
        {
            sortedQ.push_back({queries[i], i}); // value and idx
        }

        sort(sortedQ.begin(), sortedQ.end());
        // everything is sorted now

        // now i would be using priority queue to store the elements so that the smallest numbers appears first
        // because lets suppose if i am exploring for query 5 and i get top of queue 6 so it would stop even though i have
        //  4 beneath i wont be able to explore that

        // would be storing value and then the co-ordinates
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<int> ans(queries.size());
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        pq.push({grid[0][0], 0, 0}); // a vector of 3 elements,startValue,i,j
        visited[0][0] = true;

        int cnt = 0;
        // now iterte over the sortedQ
        for (int i = 0; i < sortedQ.size(); i++)
        {
            int value = sortedQ[i].first;
            int idx = sortedQ[i].second; // where the answers to be pushed to the original idx of that query

            while (!pq.empty() && pq.top()[0] < value) // pq.top()[0] is the value of the cell
            {
                int i = pq.top()[1];
                int j = pq.top()[2];
                pq.pop();
                cnt++;

                // now explore all the directions from current cell
                for (auto &dir : dirs)
                {
                    int i_ = i + dir[0];
                    int j_ = j + dir[1];

                    if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && !visited[i_][j_])
                    {
                        pq.push({grid[i_][j_], i_, j_});
                        visited[i_][j_] = true;
                    }
                }
            }

            // push the count explored
            ans[idx] = cnt;
        }

        return ans;
    }
};

// approach 2 (DFS)- tle
class Solution
{
public:
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    void helper(vector<vector<int>> &grid, int value, int i, int j, int m, int n, vector<vector<bool>> &visited, int &points)
    {
        // check constraints
        if (i >= m || i < 0 || j >= n || j < 0 || visited[i][j] || grid[i][j] >= value)
            return;

        visited[i][j] = true;
        points++;

        for (auto &dir : dirs)
        {
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            helper(grid, value, i_, j_, m, n, visited, points);
        }
    }
    vector<int> maxPoints(vector<vector<int>> &grid, vector<int> &queries)
    {

        // DFS Approach --> TC : O((m*n)*Q) would give TLE
        int m = grid.size();
        int n = grid[0].size();

        vector<int> ans;
        for (auto &query : queries)
        {
            int cnt = 0;

            vector<vector<bool>> visited(m, vector<bool>(n, false));
            int points = 0;
            helper(grid, query, 0, 0, m, n, visited, points);

            ans.push_back(points);
        }

        return ans;
    }
};

// approach 3 (BFS) -tle
class Solution
{
public:
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    void helper(vector<vector<int>> &grid, int value, int i, int j, int m, int n, vector<vector<bool>> &visited, int &points)
    {
        visited[i][j] = true;

        queue<pair<int, int>> q; // to store the co-ordinates
        q.push({0, 0});          // storing the starting idx

        while (!q.empty())
        {
            auto topy = q.front();
            q.pop();
            int i_ = topy.first;
            int j_ = topy.second;

            if (grid[i_][j_] >= value)
                continue; // skip that iteration

            points++;
            // now explore all the 4 directions
            for (auto &dir : dirs)
            {
                int iNew = i_ + dir[0];
                int jNew = j_ + dir[1];

                if (iNew >= m || iNew < 0 || jNew >= n || jNew < 0 || visited[iNew][jNew] || grid[iNew][jNew] >= value)
                    continue;

                else
                {
                    visited[iNew][jNew] = true;
                    q.push({iNew, jNew});
                }
            }
        }
    }
    vector<int> maxPoints(vector<vector<int>> &grid, vector<int> &queries)
    {

        // BFS Approach T.C => O((m*n)*Q)
        int m = grid.size();
        int n = grid[0].size();

        vector<int> ans;
        for (auto &query : queries)
        {
            vector<vector<bool>> visited(m, vector<bool>(n, false));
            int points = 0;
            helper(grid, query, 0, 0, m, n, visited, points);

            ans.push_back(points);
        }

        return ans;
    }
};

// approach 4 Recursion is same as DFS -tle
class Solution
{
public:
    void helper(vector<vector<int>> &grid, int value, int i, int j, int m, int n, vector<vector<bool>> &visited, int &points)
    {
        // check constraints
        if (i >= m || i < 0 || j >= n || j < 0 || visited[i][j] || grid[i][j] >= value)
            return;

        visited[i][j] = true;
        points++;

        // go top
        helper(grid, value, i - 1, j, m, n, visited, points);

        // go bottom
        helper(grid, value, i + 1, j, m, n, visited, points);

        // go right
        helper(grid, value, i, j + 1, m, n, visited, points);

        // go left
        helper(grid, value, i, j - 1, m, n, visited, points);
    }
    vector<int> maxPoints(vector<vector<int>> &grid, vector<int> &queries)
    {

        // general recursion which is same as doing DFS T.C => O((m*n)*Q)
        int m = grid.size();
        int n = grid[0].size();

        vector<int> ans;
        for (auto &query : queries)
        {
            int cnt = 0;

            vector<vector<bool>> visited(m, vector<bool>(n, false));
            int points = 0;
            helper(grid, query, 0, 0, m, n, visited, points);

            ans.push_back(points);
        }

        return ans;
    }
};

int main()
{

    return 0;
}