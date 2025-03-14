#include <bits/stdc++.h>
using namespace std;

// LC-210
// have to check whether it is possible to complete all the courses(finding whether there is loop or not)
// return the ordering if possible to complete(topological sort)

// BFS APPROACH
vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
    // doing by BFS i.e kahns algorithm
    // first check whether there exists a loop or not

    unordered_map<int, vector<int>> mapy; // u-->v
    vector<int> inDegree(numCourses);

    for (auto &pre : prerequisites)
    {
        int u = pre[1];
        int v = pre[0];

        // u-->v
        mapy[u].push_back(v);
        // as there is dependency on v so increase the indegree
        inDegree[v]++;
    }

    queue<int> q;
    for (int i = 0; i < inDegree.size(); i++)
    {
        if (inDegree[i] == 0)
            q.push(i);
    }

    // int cnt=0; //to check whether there is loop or not
    vector<int> topoSort;
    while (!q.empty())
    {
        auto u = q.front();
        topoSort.push_back(u);

        q.pop();

        for (auto &v : mapy[u])
        {
            inDegree[v]--;

            if (inDegree[v] == 0)
            {
                q.push(v);
            }
        }
    }

    if (topoSort.size() == numCourses)
        return topoSort;

    return {};
}
int main()
{

    return 0;
}