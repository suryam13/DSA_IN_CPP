#include<bits/stdc++.h>
using namespace std;

//GFG 
//used kahn algorithm to detect cycle

/*
  // Function to detect cycle in a directed graph.
    bool isCyclic(vector<vector<int>> &adj) {
        
        //using bfs that is using kahns algorithm,this algo works for directed acyclic graph
        //if it doesnt works for this means there is surely a cycle
        
        
        
        //finding out the indegree
        vector<int> inDegree(adj.size(),0);
        
        for(auto &vertex:adj)
        {
            for(auto &edges:vertex)
            {
                inDegree[edges]++;   
            }
        }
        
        //pushing the vertices having 0 indegree
        queue<int> q;
        for(int i=0;i<inDegree.size();i++)
        {
            if(inDegree[i]==0)
            q.push(i);
        }
        
        int check_cnt=0;
       
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            check_cnt++;
            for(auto& v:adj[u])
            {
                //since the parent is been removed so the indegree would be reduced by 1
                inDegree[v]--;
                if(inDegree[v]==0) //push into the q
                q.push(v);
            }
        }
        
        return check_cnt!=adj.size();
        //if the count of vertices is not equal to the number of vertices in the graph then there is surely a cycle
        
    }
*/

 int main()
{
    
    return 0;
}