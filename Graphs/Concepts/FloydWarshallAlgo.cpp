#include<bits/stdc++.h>
using namespace std;

/*

Floyd Warshall Algorithm :
This algo is based on multisource shortest path means at a point if u want to find the minimum cost from one vertex to all the vertices then this algo is used.
In this we find shortest path between all pairs of vertices

The difference between floyd warshall and dijkstra is that in dijkstra we are finding the minimum cost from one vertex to all the vertices but in floyd warshall we are finding the minimum cost from all the vertices to all the vertices in one go.

Time complexity of floyd warshall is O(N^3) and space complexity is O(N^2) as we are storing the distance in a 2D array.

Floyd Warshall can deal with -ve edges while dijkstra cannot
Floyd warshall can help identifying if there exists negative cycles,how?
to be obvious,in order to go from 0 to 0 the minimum cost required is 0 but lets suppose if we meet a negative cycle where,adj list is like
0->1 cost -3
1->2 cost -2
2->0 cost 1

now when we check to go from 0 to 0 via 1 and we get the minimum cost as -4 so we would blindly update that
but no,after the process check all the diagonal el if any of them is  < 0 ? "-ve cycle":"no cycle" 





CODE: 
void floydWarshall(vector<vector<int>> &dist) {
        
        //T.C. O(N^3)
        int n =dist.size();
        for(int via=0;via<n;via++)
        {
            //now go through each via
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {   
                    //handling the overflow condition if there is no path so please dont
                    //explore as it could give undesired results,and infinity means there is no path found uptill now so how could we find the cost between that

                    if(dist[i][via]!=1e8 && dist[via][j]!=1e8) //means there should exist distance between both the new edges to be considered
                    dist[i][j]=min(dist[i][j],dist[i][via]+dist[via][j]);
                }
            }
        }

        //check negative cycle
        for(int i = 0;i<n;i++)
        {
            if(dist[i][i] < 0) //diagonal element
            return -1;
        }

    }
*/
 int main()
{
    
    return 0;
}