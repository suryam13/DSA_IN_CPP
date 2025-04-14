#include<bits/stdc++.h>
using namespace std;

//LC-785 
//If it is able to partition the graph into two parts or to color with two colors such that no adjacent vertices have the same color then it is bipartite graph.
//If the graph has odd cycle then it is not bipartite graph
//GFG
//DFS
bool checkBipartite(vector<vector<int>>& adj, vector<int> &color,int currColor,int u)
{
    //color the currrent vertex
    color[u]=currColor;
    
    //visit the neighbours
    for(auto &v:adj[u])
    {
        if(color[u]==color[v]) //means visited and colored,so not able to color
        return true;
        
        if(color[v]==-1) //means not colored
        {
            color[v]=1-color[u];
            
            if(checkBipartite(adj,color,color[v],v))
            return true;
        }
    }
    return false;
}
bool isBipartite(vector<vector<int>>& adj) {
    
    //-1 means not colored,0 means red,1 means blue
    vector<int> color(adj.size(),-1);
    
    
    
    for(int i=0;i<adj.size();i++)
    {   
        //sending to start with red color
        if(color[i]==-1 && checkBipartite(adj,color,0,i))
        //means not able to color differently
        return false;
    }
    return true;
}

//BFS
bool checkBipartite(vector<vector<int>>& adj, vector<int> &color,int currColor,int u)
{
    //doing bfs

    queue<int> q;
    q.push(u);
    color[u]=currColor;

    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        for(int &v:adj[u])
        {   
            if(color[u]==color[v])  //means same color so not bipartite
            return true;

            if(color[v]==-1) //means not visited
            {
               q.push(v);
               color[v]=1-color[u]; //if it was 0 then newcolor becomes 1,if 1 then becomes 0
            }

        }
    }
    //means all were able to get colored
    return false;
}

bool isBipartite(vector<vector<int>>& adj) {

    //-1 means not colored,0 means red,1 means blue
    vector<int> color(adj.size(),-1);

    for(int i=0;i<adj.size();i++)
    {   
        //if -1 means not colored means not visited,sending to start with red color
        if(color[i]==-1 && checkBipartite(adj,color,0,i)) //if true comes means not able to color differently
        return false;
    }
    return true;
}


//Another approach by checking whether odd length cycle exits or not here the counter logic wont work like starting from 1 and if visited check mod equal 1 or not becuase suppose the graph is like
/*
if i check at 4 the counter would be 5 and on mod check it will give odd length but actually it is not
0 
|
1 - 2
|   |
4 - 3

bool oddCycle(vector<vector<int>>& adj, vector<bool> &visited, vector<int> &distance, int u, int parent) {
    for(auto &v : adj[u]) {
        if(v == parent) continue;
        
        if(!visited[v]) {
            visited[v] = true;
            distance[v] = distance[u] + 1;
            if(oddCycle(adj, visited, distance, v, u))
                return true;
        }
        // If v is visited and not parent, check if cycle length is odd
        else {
            // Cycle length = distance[u] - distance[v] + 1
            if((distance[u] - distance[v] + 1) % 2 == 1)
                return true;
        }
    }
    return false;
}

bool isBipartite(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);
    vector<int> distance(n, 0);
    
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            visited[i] = true;
            if(oddCycle(adj, visited, distance, i, -1))
                return false;
        }
    }
    return true;
}

*/
 int main()
{
    
    return 0;
}