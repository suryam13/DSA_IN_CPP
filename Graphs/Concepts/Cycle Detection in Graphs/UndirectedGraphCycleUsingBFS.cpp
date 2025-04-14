#include<bits/stdc++.h>
using namespace std;

//GFG
/*
 // Function to detect cycle in an undirected graph.

    bool bfs(vector<vector<int>>& adj,vector<bool> &visited,int u)
    {
        queue<pair<int,int>> q; //vertex and its parent
        q.push({u,-1}); //-1 because it is the starting vertex so no parent
        visited[u]=true;
        
        while(!q.empty())
        {
            auto top=q.front();
            int u=top.first; // extracted the vertex
            int parent=top.second;
            
            q.pop();
            
            
            for(int &v : adj[u])
            {
                if(v == parent )
                continue;
                
                if(visited[v] && v!=parent)
                return true;
                
                visited[v]=true;
                q.push({v,u}); // pushing the vertex and its parent
            }
        }
        return false;
    }
    bool isCycle(vector<vector<int>>& adj) {
        
        vector<bool> visited(adj.size(),false);
       
        
        //as we can have componenets that is disconnected graph so lets take a while loop
        
        for(int i=0;i<adj.size();i++)
        {
            if(!visited[i] && bfs(adj,visited,i))
            return true; //means there is a cycle
            
        }
        return false;
    }
*/
 int main()
{
    
    return 0;
}