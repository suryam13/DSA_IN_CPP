#include<bits/stdc++.h>
using namespace std;

/*

TREE : 
In order to find diameter in a tree what we do is we apply the same logic of finding a height but at each node when it goes due to recursion 
we also find the current node left + right + 1 distance as it could also be the longest diameter and keep the maximum track of it and then simply send max(left,right)+1 as we do to find the height 

GRAPH : 
In graph what we do is we simply take a vertex and find the longest distance node which is present lets say V1
Now this V1 is surely an endpoint of the longest diameter in a graph 
Now from V1 find the longest distance vertex which is present lets say V2 not this V1+V2 distance is the longest diameter in the graph

For finding the longest distance from a path to another take a queue and push all the current vertex outgoing edges and perform a level order traversal i.e inside a loop,loop till !q.empty() and always increase 1 at the end of each level order traversal thats how we can find the longest distance of one node to another node


*/
 int main()
{
    
    return 0;
}