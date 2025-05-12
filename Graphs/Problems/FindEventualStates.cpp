#include <bits/stdc++.h>
using namespace std;

// LC-802 Sheet
class Solution
{
public:
    bool helper(vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &inRecursion, int u)
    {

        visited[u] = true;
        inRecursion[u] = true;

        // marked the current vertex as visited
        // marked the current vertex to be inRecursion

        for (int &v : adj[u]) // iterating on possible edges
        {
            if (visited[v] && inRecursion[v])
                return true; // as this is a sign of cycle so return true;

            // else make a call for next
            if (!visited[v] && helper(adj, visited, inRecursion, v))
                return true;
        }

        inRecursion[u] = false;

        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {

        // the ones who doesnt get trapped in a cycle may ultimately reach the safe state
        // can do the same question with kahns algorithm too but in that we will have to reverse the graph because we
        // dont do so then we wont have any other edges from there to traverse from the 0 indegree,the ones who would
        // be visited would be marked as safe ones and that would be the answer
        int n = graph.size();
        vector<bool> visited(n, false);
        vector<bool> inRecursion(n, false);

        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                helper(graph, visited, inRecursion, i);
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (inRecursion[i] != true) // means they are been marked as false in inRecursion as they were not a part of cycle
                ans.push_back(i);
        }

        return ans;
    }
};

int main()
{

    return 0;
}