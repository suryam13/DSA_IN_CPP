#include <bits/stdc++.h>
using namespace std;

// GFG
// TC O(V*E)
vector<int> bellmanFord(int V, vector<vector<int>> &edges, int src)
{

    vector<int> cost(V, 1e8);

    cost[src] = 0;

    // have to relax v-1 times
    for (int i = 1; i <= V - 1; i++)
    {
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int c = edge[2];

            // check whether it can be relaxed or not

            if (cost[u] != 1e8 && cost[u] + c < cost[v]) // then relax
            {
                cost[v] = cost[u] + c;
            }
        }
    }

    // check one more to check whether there exists any -ve cycle
    for (auto &edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int c = edge[2];

        // check whether it can be relaxed or not

        if (cost[u] != 1e8 && cost[u] + c < cost[v]) // then relax
        {
            return {-1}; // negative cycle
        }
    }

    return cost;
}

int main()
{

    return 0;
}