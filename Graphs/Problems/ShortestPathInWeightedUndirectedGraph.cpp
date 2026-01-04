#include <bits/stdc++.h>
using namespace std;
 
// GFG
vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
{

    // constructing the adj list
    unordered_map<int, vector<pair<int, int>>> adj; // src->{dest,cost}

    for (auto &edge : edges)
    {
        int a = edge[0];
        int b = edge[1];
        int c = edge[2]; // weight/cost

        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    vector<int> cost(n + 1, INT_MAX); // since the numbering is 1

    //{cost,node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    cost[1] = 0;

    // we also have to send the path so would use a parent vector that is from where the
    // value in the specific node came
    vector<int> parent(n + 1);
    for (int i = 0; i <= n; i++)
    {
        parent[i] = i; // all will be parent of themselves in the initial stage
    }

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
                parent[node2] = node1; // updating the parent of this node2 as node1 as it got the better answer from that path
                pq.push({currCost, node2});
            }
        }
    }

    if (cost[n] == INT_MAX)
        return {-1};

    // if no path means the cost woud be INT_MAX so return -1;

    // now we have got the best answer updating the path in order to send

    // find the path for node n
    int node = n;
    vector<int> path;
    while (parent[node] != node)
    {
        path.push_back(node);
        node = parent[node];
    }

    path.push_back(node); // inserting the last vertex in the path as it wont be entered
    // as the loop would be terminated one step earlier

    path.push_back(cost[n]); // pushing the optimal cost to reach the dest
    reverse(path.begin(), path.end());
    return path;
}
int main()
{

    return 0;
}