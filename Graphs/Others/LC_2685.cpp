#include <bits/stdc++.h>
using namespace std;
void dfs(unordered_map<int, vector<int>> &adj, vector<bool> &visited, int u, int &vertices, int &edges)
{
    visited[u] = true;
    vertices++;             // increment vertices
    edges += adj[u].size(); // how many edges ?

    for (auto &v : adj[u])
    {
        if (!visited[v])
            dfs(adj, visited, v, vertices, edges);
    }
}

int countCompleteComponents(int n, vector<vector<int>> &edges)
{

    // can be done using bfs,dfs,dsu
    /*
    For a complete graph i.e it every vertex should be connected to each other vertex present in the component
    if there are n vertices then it should have n*(n-1) edges in total as it is undirected graph so it should
    have actually n/2 visible edges ex: if there is 3 vertices then it should have 6 edges that is 6/2 edges
    But as we are dealing with undirected graph then there would be multiple edges count so v* v-1 == edges
    */

    // making adj list
    unordered_map<int, vector<int>> adj;
    vector<bool> visited(n, false);
    int cnt = 0;

    for (auto &edge : edges)
    {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    // making components
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            int vertices = 0; // count vertices
            int edges = 0;    // count edges
            dfs(adj, visited, i, vertices, edges);
            if (vertices * (vertices - 1) == edges)
                cnt++;
        }
    }

    return cnt;
}
int main()
{

    return 0;
}