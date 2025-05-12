#include <bits/stdc++.h>
using namespace std;

// LC - 787 Sheet
class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {

        // here for using dikstra the cost < logic wont wor because it might be possible that
        // there was some good path to the dest which got laid off due to this logic as we would
        // have to concurrently check both the steps and the cost <

        // would be using simple bfs uptill the limit of k
        queue<pair<int, int>> q;

        // making adj list
        unordered_map<int, vector<pair<int, int>>> adj;

        for (auto &vec : flights)
        {
            int u = vec[0];
            int v = vec[1];
            int cost = vec[2];

            adj[u].push_back({v, cost});
        }

        vector<int> cost(n, INT_MAX);

        q.push({0, src});
        cost[src] = 0;
        int stops = 0;

        while (!q.empty() && stops <= k)
        {
            int size = q.size();

            while (size--)
            {
                auto topy = q.front();
                q.pop();
                int costy = topy.first;
                int desty = topy.second;

                // iterate over desty
                for (auto &v : adj[desty])
                {
                    int newV = v.first;
                    int newCost = v.second;

                    if (costy + newCost < cost[newV])
                    {
                        cost[newV] = costy + newCost;
                        q.push({costy + newCost, newV});
                    }
                }
            }
            stops++;
        }
        return cost[dst] != INT_MAX ? cost[dst] : -1;
    }
};
int main()
{

    return 0;
}