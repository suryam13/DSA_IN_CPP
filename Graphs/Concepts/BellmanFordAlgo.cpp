#include <bits/stdc++.h>
using namespace std;

/*
Used for shortest path from source to all vertices in graph

This new algo was been introduced because :
1.Dijkstra's doesnt work with -ve edges
ex: 0 -- 1 and the cost between them is -1 so they would keep on updating each other as there would be always be minimum inserted into the min heap

2.As it could not deal with -ve edges so it couldnt deal with negative cycles too.Negative cycles means the overall sum of the edges is negative,so in Dijkstras it would keep updating minimum and wont stop

Then the question comes why cant we use Bellman Ford algo in place of Dijkstra's algo as it can deal with negative edges and cycles too,so the answer is that it is not efficient as it takes O(VE) time complexity and Dijkstra's takes O(E log V) so in case of dense graph where E=V^2 then Dijkstra's would be more efficient

Bellman Ford Algo :
It is applicable on directed graph only,in order to use it in undirected process the edge twice back and forth

This Algo states that if we have V vertices then we need to relax the edges V-1 times and then we would be able to get the minimum cost from source to all the vertices present in the graph.

What is relaxation of edges :
Its nothing just checking whether the current cost is less then the previous cost or not,if yes then update the value in the vector and push it into the min heap.This process at once is a single relaxation and we need to do it V-1 times

Relax the given edges in order only,whatsoever u follow

Why deos bellman ford states that relax V-1 times only,because at min that times u have to perform relaxation after that doesnt matter how many times you do it it would not make any difference as the cost would be same and the path would be same and the min cost would have been finalised.
eg :0->1->2->3 all have cost 1

How to detect negative cycle?
if we relax the edges V-1 times and then again if we relax the edges and in the process if we get any edge which is getting relaxed then we can say that there is a negative cycle present in the graph

If we get negative cycle then it is not possible to get the minimum cost as it would keep on updating the cost and we would not be able to get the final answer

eg : a loop with net cost negative a src again coming back to it would keep updating the cost and we would not be able to get the final answer

Now again a question might we come if we are able not able to deal when negative cycle arrives then we could use dijkstra for the same but no because in dijkstra we use a pq aNd it would keep pushing elements so it couldnt handle negative weights manipulation and also the order of elements in pq would change and we are not allowed to change the order of relaxation once followed.


DIFFERENCE BETWEEN DIJKSTRAS AND BELLMAN
   DIJKSTRA                                BELLMAN
1.WORKS WITH BOTH DIRECTED          1.WORKS WITH BOTH DIRECTED
  AS WELL AS UNDIRECTED.              AS WELL AS UNDIRECTED.(HAVE TO CONVERT UNDIRECTED TO DIRECTED)

2.CANT WORK WITH -VE EDGES          2.WORKS WITH -VE EDGES TOO (DIRECTED ONLY BECAUSE IN UNDIRECTED WE HAVE TO CONVERT INTO DIRECTED WHICH WILL
                                       FORM NEGATIVE LOOP)

3.CANT HANDLE NEGATIVE CYCLES       3.HELPS DETECTING -VE CYCLES (CHECK BY RELAXING EDGES ONE MORE TIME)


//TC : O(V*E), hence dijkstras isbetter since it has O(E log V) time complexity

CODE :
vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {


       vector<int> cost(V,1e8);

       cost[src]=0;

       //have to relax v-1 times
       for(int i=1;i<=V-1;i++)
       {
           for(auto &edge:edges)
           {
               int u = edge[0];
               int v = edge[1];
               int c = edge[2];

               //check whether it can be relaxed or not

               if(cost[u]!=1e8 && cost[u] + c < cost[v]) //then relax , 1e8 check is because there should be some distance present to reach u coz
               //if we have not reached u then how could we reach v 
               {
                   cost[v]=cost[u]+c;
               }
           }
       }

       //check one more to check whether there exists any -ve cycle
       for(auto &edge:edges)
           {
               int u = edge[0];
               int v = edge[1];
               int c = edge[2];

               //check whether it can be relaxed or not

               if(cost[u]!=1e8 && cost[u] + c < cost[v]) //then relax
               {
                   return {-1}; //negative cycle
               }
           }


        return cost;

    }
*/
int main()
{
    return 0;
}