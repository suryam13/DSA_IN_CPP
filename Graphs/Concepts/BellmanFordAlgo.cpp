#include<bits/stdc++.h>
using namespace std;

/*
Used for shortest path from source to all vertices in graph

This new algo was been introduced because :
1.Dijkstra's doesnt work with -ve edges
ex: 0 -- 1 and the cost between them is -1 so they would keep on updating each other as there would be always be minimum inserted into the min heap

2.As it could not deal with -ve edges so it couldnt deal with negative cycles too.Negative cycles means the overall sum of the edges is negative,so in Dijkstras it would keep updating minimum and wont stop

Bellman Ford Algo
It is applicable on directed graph only,in order to use it in undirected process the edge twice back and forth


*/
 int main()
{
    
    return 0;
}