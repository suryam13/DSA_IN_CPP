#include<bits/stdc++.h>
using namespace std;
//GFG

/*
  void bfs(vector<vector<int>> &adj,int u,vector<bool> &visited, vector<int> &ans)
    {
        
        queue<int> q;
        visited[u]=true;
        q.push(u);
        ans.push_back(u);
        
        
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            
            for(int &v:adj[u]) //explore the connections of u --> v
            { 
                if(!visited[v])
                {
                    visited[v]=true;
                    ans.push_back(v);
                    q.push(v);
                }
            }
        }

        
    }
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        
        
        vector<int> ans;
        vector<bool> visited(adj.size(),false);
        bfs(adj,0,visited,ans);
        
        return ans;
    }
*/
 int main()
{
    
    return 0;
}