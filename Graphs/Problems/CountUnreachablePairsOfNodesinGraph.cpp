#include <bits/stdc++.h>
using namespace std;

// Approach 1: DFS
void helper(unordered_map<int, vector<int>> &adj, vector<bool> &visited, int u, long long &size)
{
    visited[u] = true;
    size++; // counting number of visited nodes

    for (int &v : adj[u])
    {
        if (!visited[v])
            helper(adj, visited, v, size);
    }
}
long long countPairs(int n, vector<vector<int>> &edges)
{

    vector<bool> visited(n, false);
    vector<long long> sizeCompo;

    // making graph
    unordered_map<int, vector<int>> adj;
    for (auto &vec : edges)
    {
        int u = vec[0];
        int v = vec[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            long long size = 0;
            helper(adj, visited, i, size);
            sizeCompo.push_back(size);
        }
    }

    long long ans = 0;  // for storing the total number of unreachable
    long long curr = 0; // for keeping the current component count of edges
    for (auto &el : sizeCompo)
    {
        ans = ans + (curr * el);
        curr += el;
    }

    return ans;
}

// Approach 2: DSU
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

// long long countPairs(int n, vector<vector<int>> &edges)
// {
//     // DSU Approach

//     parent.resize(n);
//     rank.resize(n, 0);

//     for (int i = 0; i < n; i++)
//     {
//         parent[i] = i; // all will be parent of themselves
//     }

//     // applying DSU
//     for (auto &edge : edges)
//     {
//         // do union and make them as one component
//         // although if the parent are the same it would eb handled in the union function and returned abck as it is

//         Union(edge[0], edge[1]);
//     }

//     // now we want the number of vertices in each components so take a map and look which leader/parent has how
//     // many vertices in them

//     unordered_map<int, int> leader;
//     for (int i = 0; i < n; i++)
//     {
//         int parent = find(i); // check who is the parent
//         leader[parent]++;
//     }

//     long long ans = 0;
//     long long curr = 0;

//     for (auto &[key, value] : leader) // leader -> cnt
//     {
//         ans = ans + (curr * value);
//         curr = curr + value;
//     }
//     // multiplying the number of vertices in the first component by the second component vertices and then
//     // adding the current vertices to curr to treat as 1 component for further use

//     return ans;
// }
int main()
{

    return 0;
}