#include<bits/stdc++.h>
using namespace std;


//Toplogical Sorting Using kahns Algorithm by using BFS

/*
This uses the concept of inDegree,the vertex which has indegree as 0 can be considered to come before in the final ans as there is no vertex which comes before it 

STEPS:
1.Calculate the indegree by populating over the adj list
2.Whoever has 0 as its inorder push it into queue
3.When u pop the the element form the queue the inorder of its child reduces by one 
4.And if in that process the child inorder becomes 0 push it into queue else go ahead

*/

/*
Topo sort using BFS
CODE : 
    vector<int> topologicalSort(vector<vector<int>>& adj) {
         
        vector<int> inDegree(adj.size());
        queue<int> q;
        
        //populating inorder to get the inDegree
        for(auto vertex:adj)
        {
            for(auto edges:vertex)
            {
                inDegree[edges]++;
            }
        }
        
        //filling the q with the vertices having inDegree 0
        for(int i=0;i<inDegree.size();i++)
        {
            if(inDegree[i]==0)
            q.push(i);
        }
        
        vector<int> ans;
        
        while(!q.empty())
        {
            int u=q.front();
            ans.push_back(u);
            q.pop();
            
            for(int &v:adj[u])
            {
                inDegree[v]--;
                if(inDegree[v]==0)
                {
                    //push into the queue
                    q.push(v);
                }
            }
        }
        return ans;
        
    }
*/
 int main()
{
    
    return 0;
}