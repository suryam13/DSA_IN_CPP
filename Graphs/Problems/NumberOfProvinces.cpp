#include<bits/stdc++.h>
using namespace std;
//LC - 547
//Just have to find the number of connected components in the graph.

/*
DFS
  void dfs(unordered_map<int, vector<int>>& adj, vector<bool>& visited, int u) {
        visited[u] = true;

        for (int& v : adj[u]) {
            if (!visited[v])
                dfs(adj, visited, v);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {

        vector<bool> visited(isConnected.size(), false);

        // making adjacency lsit for reference
        unordered_map<int, vector<int>> adj;

        for (int i = 0; i < isConnected.size(); i++) {
            for (int j = 0; j < isConnected[i].size(); j++) {
                if (isConnected[i][j] == 1)
                    adj[i].push_back(j);
            }
        }

        int count = 0;
        for (int i = 0; i < isConnected.size(); i++) {
            if (!visited[i]) {
                count++;
                dfs(adj, visited, i);
            }
        }

        return count;
    }
*/

/*
BFS,doing all the operations in the given matrix itself and not using any extra space for adj list
    
 int n;
    void bfs(vector<vector<int>>& isConnected,vector<bool> &visited,int u)
    {
        queue<int> q;
        visited[u]=true;
        q.push(u); //uth row

        while(!q.empty())
        {
            int top=q.front();
            q.pop();

            for(int v=0;v<n;v++)  //going along that u and exploring all the v's
            {
                if(isConnected[top][v]==1 && !visited[v])
                {
                    visited[v]=true;
                    q.push(v);
                }
            }
        }

    }
    int findCircleNum(vector<vector<int>>& isConnected) {

        //using bfs
        n=isConnected.size();
        vector<bool> visited(n,false);
        

        int count=0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                count++;
                bfs(isConnected,visited,i);
            }
        }

        return count;

        
    }

*/
 int main()
{
    
    return 0;
}