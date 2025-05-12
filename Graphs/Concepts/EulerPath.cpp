#include <bits/stdc++.h>
using namespace std;

/*
What is Eulereian Graph?
A graph having euler path and euler circuit.
Euler Path : A path which visits every edge exactly once and is able to visit every edge in a graph.
Euler Circuit : A Euler Path which starts and ends at the same vertex.

IMP : All the vertices of non-zero degree should be in same component else not eulear.
for eg : in 1 component we have 2 edges and in the other we have 4 edges then not a eulerian graph.And if 1 component has 2 edges and the other has 0 edges then it is a eulerian graph.


if it is eulerain graph and if it is eulerian circuit then for to be all the vertices should have even degree

eg graph: start 0 end 2
    1---0
    |
    |
    |
    2---3
    |   |
    |   |
    4---5
In eulearian path : the degree of start and end vertex should be odd and all the other vertices should be even.

if it has eulear path and not euler circuit then it is called semi-eulerian graph.

Eulerian path in directed graph :
In this there comes concept of inDegree and outDegree.

so here for eulerian path there should be exactly 2 nodes whose inDegree and OutDegree is equal to 1 and all the other nodes should have inDegree and outDegree equal.

If all the inDegree and outDegree are equal then it is a eulerian circuit.In this case any vertex could be considered as start and end.

for src : outDegree - InDegree = 1
for dest : inDegree - outDegree = 1

so in case to find the eulerian path the src and dest should be found out as follows.

CODE FOR UDG :
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
*/

int main()
{

    return 0;
}