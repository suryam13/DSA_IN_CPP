#include <bits/stdc++.h>
using namespace std;

void DFS(int u, vector<int> adj[], vector<bool> &visited)
{
    visited[u] = true;

    for (auto &v : adj[u])
    {
        if (!visited[v])
        {
            DFS(v, adj, visited);
        }
    }
}

bool isConnected(vector<int> adj[], int V)
{
    // making a DFS call for any vertex with Degree > 0
    // note in UDG the size of the adj[i] is itself the count of degree there is no concept of inDegree and the OutDegree as the edges are bidirectional

    vector<bool> visited(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (adj[i].size() > 0) // go and have a check
        {
            DFS(i, adj, visited);
            break;
        }
    }

    // now iterate and check if any of the vertex with inDeg > 0 is unvisited then not a
    // eulerian graph
    for (int i = 0; i < V; i++)
    {
        if (adj[i].size() > 0 && !visited[i]) // go and have a check
        {
            return false;
        }
    }

    return true;
}

int isEulerCircuit(int V, vector<int> adj[])
{

    // checking if there are multiple components of size greater then 1,if yes then
    // false as all the edges wont be visited in a single visit

    // NOTE:A component with 0 indegree is fine
    if (!isConnected(adj, V))
        return 0;

    // if not then check for odd degree
    int oddDeg = 0;
    for (int i = 0; i < V; i++)
    {
        if (adj[i].size() & 1) // means odd
            oddDeg++;
    }

    if (oddDeg == 2)
        return 1; // eulerian path

    else if (oddDeg == 0) // means all inDeg even
        return 2;

    else
        return 0; // NONE
}

int main()
{

    return 0;
}