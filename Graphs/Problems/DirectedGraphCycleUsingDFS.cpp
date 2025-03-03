#include <bits/stdc++.h>
using namespace std;
// GFG
/*here the parent logic wont work suppose

suppose we have the relation
0->1
2->1



In this problem 1 would be previously marked and also it wont be equal to parent which is 2 in the next for loop call for non visited ones, so it would return true for cycle but it is not,in undirected it wasnt a problem because in that the movement was possible for both the sides

so we would have to keep a track of which elements are in continuos direction and if they meet again so a cycle,thats the purpose of using inRecursion so that it would keep a track of the ones involved int this call


This problem cannot be solved using topo sort as in bfs it was working but wont work over here because it would still produce the answer even if cycle exists but the answer would be wrong

So over here the standard inRecursion technique is used

bool helper(vector<vector<int>>& adj,vector<bool> &visited,vector<bool> &inRecursion,int u)
    {

        visited[u]=true;
        inRecursion[u]=true;
        //marked the current vertex as true

        for(int &v:adj[u]) //iterating on possible edges
        {


            if(visited[v]==false &&  helper(adj,visited,inRecursion,v))
            return true;

            //else make a call for next
            else if(inRecursion[v]) //means visited and inRecursion true;
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

            if(!visited[i] && helper(adj,visited,inRecursion,i)) //i is the startion vertex and
            //-1 is the parent since it is the first vertex
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

            st.erase(v);
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