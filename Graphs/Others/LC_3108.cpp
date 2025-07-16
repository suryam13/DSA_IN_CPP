#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    vector<int> parent;
    vector<int> rank;
    int find(int val)
    {
        if (parent[val] == val)
            return val;

        return parent[val] = find(parent[val]);
    }

    void Union(int x, int y)
    {
        int parent1 = find(x);
        int parent2 = find(y);

        if (parent1 != parent2)
        {
            if (rank[parent1] == rank[parent2])
            {
                rank[parent2] += 1;
                // parent 2 becomes the new parent
                parent[parent1] = parent2;
            }

            else if (rank[parent1] > rank[parent2])
            {
                // parent 1 becomes the new parent
                parent[parent2] = parent1;
            }

            else
            {
                parent[parent1] = parent2;
            }
        }   
    }

    vector<int> minimumCost(int n, vector<vector<int>> &edges, vector<vector<int>> &query)
    {

        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i; // all will be parent of themselves
        }
        /*
           The key idea is that try to do AND with all the possible values in the components as
           much we do AND the value decreases and we are allowed to visit edges multiple times so do this
           and also we are been siad to tell the minimum cost to reach from u=>v so this is the optimal
        */
        vector<int> parentAnd(n, -1);
        // if we do AND with -1 with any of the number we would get the same number

        // making components
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int cost = edge[2];

            int parentA = find(u);
            int parentB = find(v);

            if (parentA != parentB)
            { // so combine
                Union(u, v);

                // either u is parent or v is parent depending on the rank check with either of one who is the new parent
                int newParent = find(u);
                parentAnd[newParent] &= parentAnd[parentA] & parentAnd[parentB] & cost;
            }

            else // in same component so just add the current cost
                parentAnd[parentA] &= cost;
        }

        vector<int> ans;
        for (auto &q : query)
        {
            int u = q[0];
            int v = q[1];

            int parentA = find(u);
            int parentB = find(v);

            if (parentA == parentB)
            {
                ans.push_back(parentAnd[parentA]);
            }

            else // means no connection so no same component,so not possible to reach from u=>v
                ans.push_back(-1);
        }

        return ans;
    }
};
int main()
{

    return 0;
}