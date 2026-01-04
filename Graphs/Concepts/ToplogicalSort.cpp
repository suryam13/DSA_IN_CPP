#include<bits/stdc++.h>
using namespace std;

/*

What is Topo sort?
Topo sort means we have to generate the answer in such a manner that if there is a connection/edge like 2-->3 so in the answer 2 should appear before 3 as firstly 2 will come then 3

NOTE:
Toplogical Sort is applied only in directed graph as in undirected graph there is both the possibility 2 before 3 or 3 before 2,so it is unpredictible

to be specific it is possible in DIRECTED ACYCLIC GRAPH,if it contains cycle so again it would make no sense

There can be multiple topological sorting answer for a partcular DAG
 
Now for this we would use a stack as the intention is that u would come before v so push all the v into the stack then as all the connections of u are veen visited then push u.

Due to this what happens is when we pop out of stack the u comes first then the respective v,thats what we actually need if there is a connection between u and v then u should come before v


*/

/*
//GFG : TOPO SORT USING DFS

CODE :
    
    void dfsTopo(vector<vector<int>>& adj, vector<bool> &visited,stack<int> &st,int u)
    {
        //first insert all the child then the parent means first all the v's then u 
        visited[u]=true;
        
        
        for(int& v:adj[u])
        {
            if(!visited[v])
            dfsTopo(adj,visited,st,v);
        }
        
        //ab parent ke daalo 
        st.push(u);
        
    }
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        
        stack<int> st;
        vector<int> ans;
        vector<bool> visited(adj.size(),false);
        
        for(int i=0;i<adj.size();i++)
        {
            if(!visited[i])
            dfsTopo(adj,visited,st,i);
        }
        
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
*/

 int main()
{
    
    return 0;
}