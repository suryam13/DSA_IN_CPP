#include<bits/stdc++.h>
using namespace std;
//GFG

/*
//DFS traversal of graph
In DFS traversal we go in depth,that is we go from one source to its neighbour and from that neighbour we start the new exploration and then repeat the same process of visiting neighbours and in that process there is a chance that we could come at the same vertex again that is beene explored already,so for that reason we maintain a visited array to keep track of the vertices that are already been explored.


  void dfs(vector<vector<int>>& adj,int u,vector<bool>& visited,vector<int> &traversed)
    {
        if(visited[u]) //means this vertex has been visisted, if we dont write this it still works as this case is been handled in the for-loop itself
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