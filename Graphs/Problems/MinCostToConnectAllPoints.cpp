#include <bits/stdc++.h>
using namespace std;

// Prims Algo
class Solution
{
public:
    typedef pair<int, int> P;
    int minCostConnectPoints(vector<vector<int>> &points)
    {

        // we have to make a connected graph so it hints at using minimum spanning tree algorithm
        // using Prim's Algo

        // firstly we will have to make graph,as any distance could be minimum so have to connect all
        //  the edges

        unordered_map<int, vector<P>> mapy; // cost dest
        int n = points.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];

                int dist = abs(x1 - x2) + abs(y1 - y2);
                mapy[i].push_back({dist, j});
                mapy[j].push_back({dist, i});
            }
        }

        vector<bool> visited(n, false);
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, 0}); // cost dest
        int cost = 0;

        while (!pq.empty())
        {
            auto topy = pq.top();
            pq.pop();
            int costy = topy.first;
            int dest = topy.second;

            if (!visited[dest])
            {
                visited[dest] = true;
                cost += costy;

                for (auto &edge : mapy[dest])
                {
                    int newCost = edge.first;
                    int newDest = edge.second;
                    if (!visited[newDest])
                    {
                        pq.push({newCost, newDest});
                    }
                }
            }
        }

        return cost;
    }
};


// Kruskals Algo
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

    int minCostConnectPoints(vector<vector<int>> &points)
    {

        // we have to make a connected graph so it hints at using minimum spanning tree algorithm
        // using Kruskal's Algo

        // firstly we will have to make graph,as any distance could be minimum so have to connect all
        // the edges
        int V = points.size();

        parent.resize(V);
        rank.resize(V, 0);

        for (int i = 0; i < V; i++)
        {
            parent[i] = i; // all will be parent of themselves
        }

        // first i have to sort them based on their edge weights
        vector<vector<int>> edgeWeights;
        int cost = 0;

        for (int i = 0; i < V; i++)
        {
            for (int j = i + 1; j < V; j++)
            {
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];

                int dist = abs(x1 - x2) + abs(y1 - y2);

                edgeWeights.push_back({dist, i, j});
                // cost src dest
            }
        }

        sort(edgeWeights.begin(), edgeWeights.end());

        for (auto &vec : edgeWeights)
        {
            int costy = vec[0];
            int x = vec[1];
            int y = vec[2];

            int find1 = find(x);
            int find2 = find(y);

            if (find1 != find2) // means have to be connected
            {
                cost += costy;
                Union(x, y);
            }
        }

        return cost;
    }
};

int main()
{

    return 0;
}