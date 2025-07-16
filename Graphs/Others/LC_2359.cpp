#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void DFS(vector<int> &edges, int u, int &cnt, vector<int> &nody, vector<bool> &vis1)
    {
        if (u == -1 || vis1[u]) // if no edge or a cycle means repeated then return
            return;

        nody[u] = cnt;
        cnt++;

        if (!vis1[u])
        {
            vis1[u] = 1;
            DFS(edges, edges[u], cnt, nody, vis1);
        }
    }

    int closestMeetingNode(vector<int> &edges, int node1, int node2)
    {

        int n = edges.size();

        // distance vector from respective nodes
        vector<int> nody1(n, -1);
        vector<int> nody2(n, -1);

        // visited nodes set from each vector
        vector<bool> vis1(n, 0);
        vector<bool> vis2(n, 0);

        int cnt1 = 0, cnt2 = 0;
        int idx = -1;
        int mini = INT_MAX;

        DFS(edges, node1, cnt1, nody1, vis1);
        DFS(edges, node2, cnt2, nody2, vis2);

        for (int i = 0; i < edges.size(); i++)
        {
            if (nody1[i] != -1 && nody2[i] != -1) // means reachable
            {
                // we have to minimise the maximum
                if ((max(nody1[i], nody2[i])) < mini)
                {
                    mini = max(nody1[i], nody2[i]);
                    idx = i;
                }
            }
        }

        return idx;
    }
};
int main()
{

    return 0;
}