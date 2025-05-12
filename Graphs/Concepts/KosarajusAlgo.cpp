#include <bits/stdc++.h>
using namespace std;

/*
Kosaraju Algorithm is used to find strongly connected components in a directed graph only.
SCC is a subgraph in which every vertex is reachable from every other vertex in the subgraph which form a kind of loop.

We would have to do the following steps :
1. Do a DFS and push the finishing times of the nodes in a stack (this is the order in which we will be doing the dfs in the next step) because we have to find the which node has to ve visited first so that it stops under the same SCC.
NOTE : This is not the topological sort as in topological sort we have to find the order of the nodes in which they can be visited but here we have to find the finishing times of the nodes in which they can be visited so that we can find the SCC.
So only DFS Stack is used here and not the Kahn's 
algo.

2.Reverse the graph

3.Simple DFS and count in reversed graph

//TC : O(V+E) for all the steps
CODE :
void dfs(int u ,vector<vector<int>> &revAdj,vector<int> &visited)
    {
        visited[u]=true;

        for(auto &v:revAdj[u])
        {
            if(!visited[v])
            dfs(v,revAdj,visited);
        }
    }

    void sequence(int u ,vector<vector<int>> &adj,vector<int> &visited,stack<int> &st)
    {

        visited[u]=true;

        for(auto &v:adj[u])
        {
            if(!visited[v])
            sequence(v,adj,visited,st);
        }

        st.push(u);
    }
    int kosaraju(vector<vector<int>> &adj) {
        //for SCC we use Kosaraju

        //STEP 1 : we have to find a kind of sequence in which the dfs can be made so that it
        //doesnt violate the SCC (according to finishing times)

        int n = adj.size();
        stack<int> st;
        vector<int> visited(n,false);

        for(int i=0;i<n;i++){ //O(V+E)

            if(!visited[i])
            sequence(i,adj,visited,st);
        }

        //STEP 2 : now reverse the graph  O(V+E)
        vector<vector<int>> revAdj(n);
        for(int i =0;i<n;i++)
        {
            for(auto &el:adj[i])
            {
                revAdj[el].push_back(i);
            }
        }
            
        //STEP 3 : apply dfs O(V+E)
        int cnt=0;
        vector<int> newVisited(n,false);

        while(!st.empty())qq
        {
            int topy=st.top();

            if(!newVisited[topy])
            {
                dfs(topy,revAdj,newVisited);
                cnt++;
            }

            st.pop();
        }

        return cnt;
    }
*/
int main()
{

    return 0;
}