#include <bits/stdc++.h>
using namespace std;
// GFG
/*here the parent logic wont work suppose

suppose we have the graph like
0->1<-2
0 - 1
1 - no any edge
2 - 1



In this problem 1 would be previously marked in the first call for non visited ones,now in the next call 2 will be sent as the starting node amd the parent would be sent as -1 and when the edge will move to 1 it would be found as visited and would return as true for a cycle but it should not be the case,in undirected it wasnt a problem because in that the movement was possible for both the sides

so we would have to keep a track of which elements are been visited in same call and in continuous direction and if they meet again so a cycle,thats the purpose of using inRecursion so that it would keep a track of the ones involved in this call


This problem cannot be solved using topo sort,as in bfs it was working but wont work over here because it would still produce the answer even if cycle exists but the answer would be wrong,so topo sort using dfs wont work here

So over here the standard inRecursion technique is used

// Function to detect cycle in a directed graph.
 bool helper(vector<vector<int>>& adj,vector<bool> &visited,vector<bool> &inRecursion,int u)
    {
        
        visited[u]=true;
        inRecursion[u]=true;
        //marked the current vertex as visited
        //marked the current vertex to be inRecursion
        
        for(int &v:adj[u]) //iterating on possible edges
        {
          if (visited[v] && inRecursion[v])
                return true; // as this is a sign of cycle so return true;

            // else make a call for next
            if (!visited[v] && helper(adj, visited, inRecursion, v))
                return true;
        }
        
        inRecursion[u]=false;
        
        return false;
    }
    
    bool isCyclic(vector<vector<int>> &adj) {
        
          
        vector<bool> visited(adj.size(),false);
        vector<bool> inRecursion(adj.size(),false);
     
        
        //since there can be a disconected graph in the space so we need to explore all
        for(int i=0;i<adj.size();i++)
        {
            
            if(!visited[i] && helper(adj,visited,inRecursion,i))
            return true;
        
        }
        
        return false;
    }

*/
/*
Another Approach : Mine
  bool dfs(vector<vector<int>> &adj,vector<bool> &visited,unordered_set<int>& st,int u)
    {

        visited[u]=true;
        st.insert(u);


        for(int &v:adj[u])
        {

            if(visited[v] && st.count(v))
            return true;

            if(dfs(adj,visited,st,v))
            return true;

           // st.erase(v); //would work if i dont write this because it would be automatically handled by going till the end where st.erase(u) is used for the next set of call
        }

        st.erase(u);
        return false;
    }

    bool isCyclic(vector<vector<int>> &adj) {

        vector<bool> visited(adj.size(),false);
        unordered_set<int> st;

        for(int i=0;i<adj.size();i++)
        {

            if(!visited[i] && dfs(adj,visited,st,i))
            return true;
        }

        return false;

    }
*/
int main()
{

    return 0;
}