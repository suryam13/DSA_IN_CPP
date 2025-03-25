#include <bits/stdc++.h>
using namespace std;

/*

--> Dijkstras doesnt works with negative weights
--> Dijkstra's algorithm works on both directed and undirected graphs.
--> It is used to give the minimum cost to go from source to specified destination

STEPS :
--> You would be having a source from where u would be told to calculate the minimum cost required to get from there to all the vertices
--> So for obvious lets suppose u have the source as 2 then to go from source 2 to destination 2 the cost would be 0
--> now take a min heap so that the one with the minimum cost comes up and gets explored, so the very first step would be as follows 
--> the min heap which we are making is specifically for that source what ever the distances are been stored in the form of {x,y} that is from the source

STEP 1 : Push {0,2} into the min-heap 0 is the cost and 2 is the node from where it would be explored when the pair would be popped out
STEP 2 : Pop {0,2} and now cost - 0 node - 2 explore node 2 neigbours that are in the adj list the list would be containing {x,y} wherein x is the neighbour and y is the cost to go to that neighbour
STEP 3 : add the current cost and the neigbour cost then analyse whether is the optimal value if yes then update the value in the vector and add the current path into the min heap insert {a,b} where a is the cost of the current node and b is the node
STEP 4 : Keep repeating untill the q becomes empty and then retuen the answer

NOTE: Dijkstra's would work the same even with a normal queue but the concern is to be greedy we cant be greedy in this normal queue as we are not visiting the path with smallest cost first which leads to multiple checks and entries but at last we would be getting the same answer

Also we can use ordered_set in place of priority queue and even that would serve the same answer.But there is one more benefit in set that suppose if we get a better answer for a vertex then surely the previous cost that is there in the answer vector would be existing in the set as we would had thought at that time that,that value would be the best and would be needed to explore after some time but now we have got a better answer in that then we can erase that from the set as we dont want to have unnecessary checks,which was not possible to do in priority queue,so its a bit optimised but not upto that extent 
*/

/*
T.C : O( V (log V + E logV )) 
in worst case the number of edges can be V-1 in dense graph where every vertex is connected to every other vertex present in the graph i.e V-1 --> V vertices(round off)

O( V log V (1 + V ))  //taking log V common 
O(V^2 logV) assuming 1+V to be V
O(E logV)  assuming V^2=E
V^2=E since it is equivalent in case of dense graph evry node v is connected to v-1 vertices so V^2


*/
//CODE (GFG):
vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src)
{
    // i have been provided with the adj list

    // min heap to store {a,b} a-->weight b-->value
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int n = adj.size();
    vector<int> ans(n, INT_MAX);
    ans[src] = 0; // the minimum cost from src to src would be 0

    pq.push({0, src}); // since src->src would be taking 0 weight

    while (!pq.empty())  //O(V) number of vertices
    {
        // now extracting the top
        auto topy = pq.top();
        int cost1 = topy.first;  // weight
        int node1 = topy.second; // node value
        pq.pop(); //O(log V)

        // exploring neighbours
        for (auto &neighbour : adj[node1]) //O(E)
        {
            int node2 = neighbour.first;
            int cost2 = neighbour.second;

            int currCost = cost1 + cost2;
            if (ans[node2] > currCost) // then please replace as we have got a better path
            {
                ans[node2] = currCost;
                // please push this better alternative as this would be explored later
                pq.push({currCost, node2}); //O(log V)
            }
        }
    }
    return ans;
}
int main()
{

    return 0;
}