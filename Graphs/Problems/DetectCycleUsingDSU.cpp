#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> rank;
    vector<int> parent;

    void Union(int x, int y)
    {
        int x_parent = find(x);
        int y_parent = find(y);

        // if parent are same then they belong to same set so need to merge
        if (x_parent != y_parent)
        {
            if (rank[x_parent] == rank[y_parent])
            {
                rank[y_parent] += 1;
                parent[x_parent] = y_parent;
            }

            else if (rank[x_parent] > rank[y_parent])
                // then x becomes the parent
                parent[y_parent] = x_parent;

            else
                // then y becomes the parent
                parent[x_parent] = y_parent;
        }
    }

    int find(int ele)
    {

        if (ele == parent[ele]) // means the value is a parent
            return ele;

        // if not then search who is the parent of parent[i] then recursively

        return parent[ele] = find(parent[ele]);
        // optimisation
    }

    int detectCycle(int V, vector<int> adj[])
    {
        parent.resize(V);
        rank.resize(V, 0);

        for (int i = 0; i < V; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }

        for (int u = 0; u < V; u++)
        {
            for (int &v : adj[u])
            {
                if (u < v) // to avoid processing the same node again else would give cycle because it is undirected graph so if 0-->1 is processed then no need for 1-->0 process because it would give same parent
                {
                    int x_parent = find(u);
                    int y_parent = find(v);

                    if (x_parent == y_parent)
                        return 1;

                    Union(x_parent, y_parent);
                }
            }
        }
        return 0;
    }
};
int main()
{

    return 0;
}