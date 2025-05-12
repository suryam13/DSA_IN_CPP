#include <bits/stdc++.h>
using namespace std;

/*
We use Prims Algo when we need to get minimum cost to connect edges such that they are connected and can move freely
1.We want minimum cost to come up so we take a min heap
2.We store three things in min heap cost,dest,src
3. We consider the sum which is the sum of weights of edges in the MST and parent vector whcih edges are participating in the MST
CODE :

// TC : O(ElogE) or O(ElogV)
ElogE + ElogE

int spanningTree(int V, vector<vector<int>> adj[]) {

    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;

    int n=V;
    vector<int> parent(n,-1);
    vector<bool> visited(n,0);

    pq.push({0,0,-1}); //pushing '0' initially
    int sum=0; //sum of weights of edges in the MST
    while(!pq.empty()) //at max O(E) times as the visit check is inside the loop so still it would process
    {
        auto topy=pq.top();
        pq.pop();   //this would take heap size i.e O(logE) at worst case

        int cost=topy[0];
        int dest=topy[1];
        int src=topy[2]; //we do this only when the edges is been asked which are participating else no need

        //check if visited then plz dont enter as the minimum would have been considered
        if(!visited[dest])
        {   //mark visited
            visited[dest]=true;

            //update the parent of the current node
            parent[dest]=src;

            //consider the cost
            sum+=cost;

            for(auto &v:adj[dest]) // O(E) for iteration
            {
                int neighbour=v[0];
                int cost1=v[1];

                //check if the node is not visited and push it to the queue
                if(!visited[neighbour])
                {
                    pq.push({cost1,neighbour,dest}); //logE
                }

            }
        }
    }
         return sum; //return the sum of weights of edges in the MST

    }

*/
int main()
{
    return 0;
}