#include <bits/stdc++.h>
using namespace std;

/*
INTUTION :
We have to make exactly V-1 edges in the make to make the graph connected so we will try to make edge connected with a minimum weight edge and if in future the two vertices are connected then we wont connect them as we the main motive was to connect and we got them connected with the minimum edge weights before so no nee to do connect them again

Sort the edges with minimum edge weight coming first
Follow DSU approach and if the paren to two vertices are same then please dont connect them as they are been connected via minimum edge weights before

//TC : O(ElogE) for sorting and O(E*4*alpha(n)) for union and find operation

//didnt sued the optimised DSU but should use in this
    vector<int> parent;

    int find(int ele)
    {
        if(parent[ele] == ele)
        return ele;

        return parent[ele]=find(parent[ele]);
    }

    void Union(int ele1,int ele2)
    {
        int find1 = find(ele1);
        int find2 = find(ele2);

        if(find1!=find2)
        {
            parent[find1]=find2;
        }
    }

    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {


        parent.resize(V);
        for(int i=0;i<V;i++)
        {
            parent[i]=i;
        }
        //By using kruskal's algo

        //first i have to sort them based on their edge weights
        vector<vector<int>> edgeWeights;
        int cost=0;

        //O(V+E)
        int i =0;
       for(auto &v:adj){ //0th position
            for(auto &vecy:v)
            {
                edgeWeights.push_back({vecy[1],i,vecy[0]});
            }
            i++;
             //cost src dest
        }


        //O(ElogE) for sorting e edges
        sort(edgeWeights.begin(),edgeWeights.end());

        //O(E*(4*alpha)) if we use dsu by path compression and rank optimisaton
        for(auto &vec:edgeWeights)
        {
            int costy = vec[0];
            int x = vec[1];
            int y = vec[2];

            int find1 = find(x);
            int find2 = find(y);

            if(find1!=find2) //means have to be connected
            {
                cost+=costy;
                Union(x,y);
            }
        }

        return cost;
    }
*/
int main()
{

    return 0;
}