#include<bits/stdc++.h>
using namespace std;
//GFG
/*
  void dfs(vector<vector<int>>& adj,int u,vector<bool>& visited,vector<int> &traversed)
    {
        if(visited[u]) //means this vertex has been visisted, if we dont write this it still works as this case is been handled int the for loop itself
        return;
        
        //if not then mark 
        visited[u]=true;
        
        //now push
        traversed.push_back(u);
        
        //now explore the neighbours to perform dfs
        
        for(auto &v:adj[u])
        {   
            //checking here because in future recursive calls could be made again even if its marked 
            if(!visited[v])
            dfs(adj,v,visited,traversed);
        }
    
    }
        
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        
        
        vector<int> traversed;
        //to store final answer
        
        vector<bool> visited(adj.size(),false);
        //to keep track of visited vertices 
        
        dfs(adj,0,visited,traversed);
        //0 is the u means the starting vertex
        
        return traversed;
    }
*/
 int main()
{
    return 0;
}