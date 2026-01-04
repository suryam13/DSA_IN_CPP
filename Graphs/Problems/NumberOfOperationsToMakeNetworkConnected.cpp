#include <bits/stdc++.h>
using namespace std;

// LC 1319
void dfs(int u, vector<bool> &visited, unordered_map<int, vector<int>> &mapy)
{
    visited[u] = true;

    for (auto &v : mapy[u])
    {
        if (!visited[v])
            dfs(v, visited, mapy);
    }
}
int makeConnected(int n, vector<vector<int>> &connections)
{

    if (connections.size() < n - 1) // we need atleast n-1 wires to connect n components
        return -1;

    unordered_map<int, vector<int>> mapy;
    for (auto &connect : connections)
    {
        mapy[connect[0]].push_back(connect[1]);
        mapy[connect[1]].push_back(connect[0]);
    }

    // make components
    int cnt = 0;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            cnt++;
            dfs(i, visited, mapy);
        }
    }

    return cnt - 1;
}

// DSU APPROACH
// vector<int> parent;
// vector<int> rank;
// int find(int val)
// {
//     if (parent[val] == val)
//         return val;

//     return parent[val] = find(parent[val]);
// }

// void Union(int x, int y)
// {
//     int parent1 = find(x);
//     int parent2 = find(y);

//     if (parent1 != parent2)
//     {
//         if (rank[parent1] == rank[parent2])
//         {
//             rank[parent2] += 1;
//             // parent 2 becomes the new parent
//             parent[parent1] = parent2;
//         }

//         else if (rank[parent1] > rank[parent2])
//         {
//             // parent 1 becomes the new parent
//             parent[parent2] = parent1;
//         }

//         else
//         {
//             parent[parent1] = parent2;
//         }
//     }
// }


// int makeConnected(int n, vector<vector<int>> &connections)
// {
//     /*
//     By Using DSU,make components which belongs to the same parent then n components are remaining so n-1
//     wires required to connect them
//     */

//     parent.resize(n);
//     rank.resize(n, 0);

//     for (int i = 0; i < n; i++)
//     {
//         parent[i] = i; // all will be parent of themselves
//     }

//     if (connections.size() < n - 1) // to connect n components in UDG we need at least n-1 wires/edges
//         return -1;

//     int cnt = n;
//     for (auto &connection : connections)
//     {
//         int par1 = find(connection[0]);
//         int par2 = find(connection[1]);

//         if (par1 == par2) // means same parent then no need to attach we have got extra wire
//             continue;

//         else
//         {
//             Union(par1, par2);
//             cnt--;
//         } // as one component got decreased
//     }

//     return cnt - 1; // means size - 1 is the number of wires required to connect these n components
// }

int main()
{

    return 0;
}