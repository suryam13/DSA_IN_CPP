#include <bits/stdc++.h>
using namespace std;
// LC 743
int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    // directed graph applying dijkstra's algo
    // k is the src node

    // adj list
    unordered_map<int, vector<pair<int, int>>> adj; // src->{dest,cost}

    for (auto &time : times)
    {
        int u = time[0];
        int v = time[1];
        int c = time[2]; // weight/cost

        adj[u].push_back({v, c}); // since it is a directed graph
    }

    vector<int> cost(n + 1, INT_MAX); // since the numbering is 1

    //{cost,node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, k}); // since k is th source node
    cost[k] = 0;

    while (!pq.empty())
    {
        auto topy = pq.top();
        int cost1 = topy.first;
        int node1 = topy.second;
        pq.pop();

        for (auto &neighbours : adj[node1])
        {

            int cost2 = neighbours.second;
            int node2 = neighbours.first;

            int currCost = cost1 + cost2;

            if (currCost < cost[node2])
            {
                cost[node2] = currCost;
                pq.push({currCost, node2});
            }
        }
    }

    // now we have to check whether it is possible to visit each network or not,if yes then send the minimum
    // time to reach all nodes,means we will have to send the max cost that appears in the cost vector,if
    // any of remains to be INT_MAX means not possible to go over there so return -1;

    int max_time = 0;
    for (int i = 1; i <= n; i++) // as the numbering starts from 1
    {
        if (cost[i] == INT_MAX)
            return -1;
        max_time = max(max_time, cost[i]);
    }

    return max_time;
}
int main()
{
    return 0;
}