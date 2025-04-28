#include <bits/stdc++.h>
using namespace std;

// GFG
//In undirected graph u just have to make sure that if it comes again to a previously visited vertex then it is a cycle but make sure that the edge is not going back to the parent vertex because suppose we have a graph like this a---b so if we go from a to b then we would also have an edge from b to a but since a is visited we would return a cycle but actually it is not a cycle because where b is going it is a parent of b,we cannot use the same edge to go back to a vertex,we need to have independent edges to go,although undirected graph provides back and forth movement but this case is not considered in the cycle detection,hence it is not a cycle. 
/*
 bool helper(vector<vector<int>>& adj,vector<bool> &visited,int u,int parent)
    {

        visited[u]=true;
        //marked the current vertex as true

        for(int &v:adj[u]) //iterating on possible edges
        {
            if(parent==v) //so dont go back as it would be marked but not a cycle
            continue;

            if(visited[v])
            return true; //as this is a sign of cycle so return true;

            //else make a call for next
            if(helper(adj,visited,v,u)) //send the current u as the parent and if true
            //means cycle detected
            return true;
        }

        return false;


    }
    bool isCycle(vector<vector<int>>& adj) {

        vector<bool> visited(adj.size(),false);

        //since there can be a disconected graph in the space so we need to explore all
        for(int i=0;i<adj.size();i++)
        {

            if(!visited[i] && helper(adj,visited,i,-1)) //i is the starting vertex and
            //-1 is the parent since it is the first vertex
            return true;
        }

        return false;

    }
*/
int main()
{

    return 0;
}