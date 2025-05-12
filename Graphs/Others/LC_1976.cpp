#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int countPaths(int n, vector<vector<int>> &roads)
{
    // graph construction
    unordered_map<int, vector<pair<int, int>>> adj;
    int MOD = 1e9 + 7;

    for (auto &road : roads)
    {
        int u = road[0];
        int v = road[1];
        int cost = road[2];

        adj[u].push_back({v, cost});
        adj[v].push_back({u, cost});
    }

    vector<int> county(n, 0); // count how many ways are there to come at this position in optimal cost ?
    vector<ll> cost(n, LONG_MAX);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, 0}); // cost,node
    cost[0] = 0;
    county[0] = 1; // at the starting there is 1 way that is itself

    while (!pq.empty())
    {
        auto topy = pq.top();
        int node1 = topy.second;
        ll cost1 = topy.first;
        pq.pop();

        for (auto &neighbours : adj[node1])
        {
            int node2 = neighbours.first;
            int cost2 = neighbours.second;
            ll currCost = cost1 + cost2;

            if (cost[node2] > currCost) // replace as we have got better cost
            {
                cost[node2] = currCost;
                county[node2] = county[node1]; // reset the count to the ways earlier node1 had
                pq.push({currCost, node2});
            }

            else if (cost[node2] == currCost)
            {
                // means there is another node 1 route which leads to this node2 so add the count of that
                // different route instead of resetting it
                county[node2] = (county[node2] + county[node1]) % MOD;
            }
        }
    }

    return county[n - 1] % MOD;
}
int main()
{

    return 0;
}