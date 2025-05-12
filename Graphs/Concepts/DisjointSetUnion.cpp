#include <bits/stdc++.h>
using namespace std;
/*
DSU only works with undirected graph as it used for cycle detection and component making while in directed graph it only works for making weakly connected components and not strongly connected components and also not for cycle detection 

FOR COMPONENT MAKING :
Undirected,Directed(WCC) : DSU,BFS,DFS
Directed(SCC) : BFS,DFS,Kosaraju

CONCEPT OF DISJOINT SET OR UNION FIND
works only in undirected graph and not in directed
What is Disjoint set ?

Lets suppose there are many components and when i take intersection of all these components the result turns out to be NULL.

DSU gives us two operations :
1. Combine two given sets
2. Tell whether two members belong to same set or not

TC :O(4*alpha(n)) n is number of elements in the disjoint set and alpha is the inverse of Ackermann function which is a very slow growing function
If i find suppose 'c' and then for 'd' and if they belong to same parent/leader then they belong to same set

There is also union by size where it is possible to state the size of the component by checking the size of the parent over here we dont add +1 instead we do size[parent1]+=size[parent2]

Find function to find out the parent/leader of an element

//takes O(N) in worst case in case of skewed tree
int find(int ele,vector<int> &parent)
{

    if (ele==parent[ele]) //means the value is a parent
    return ele;


    //if not then search who is the parent of parent[i] then recursively
    return find(parent[ele],parent)
}



Union function to merge any two vertices as given,in this we will first have to find parent/leader of both of this vertices and then make any one of them as the parent of other to merge

void union(int x,int y,vector<int> &parent)
{
    int x_parent=find(x,parent);
    int y_parent=find(y,parent);

    //if parent are same then they belong to same set so need to merge
    if(x_parent!=y_parent)
    {
        parent[x_parent]=y_parent;

        //making y as parent of x can do either ways too
    }
}


//The find action takes a long time as it has to go uptill the top in worst case so for that reason we have find operation using rank and path compression

//optimized the find operation using path compression : we know that it would be traversed again and again at the top so why not when coming back assign all the nodes their topmost parent so that they can find directly next time without traversing entire path


int find(int ele,vector<int> &parent)
{

    if (ele==parent[ele]) //means the value is a parent
    return ele;


    //if not then search who is the parent of parent[i] then recursively

    return parent[ele]=find(parent[ele],parent)
    //optimisation
}


//optimised the union operation 
//Rank optimsation is done to make sure the tree doesnt grow bigger,initially the rank of all the elements would be 0 if same rank then increment the rank by 1 of any element and make it as a parent else the one with higher rank gets to be the parent

we take an extra vector rank over here

void union(int x,int y,vector<int> &parent)
{
    int x_parent=find(x,parent);
    int y_parent=find(y,parent);

    //if parent are same then they belong to same set so need to merge
    if(x_parent!=y_parent)
    {
        if(rank[x_parent] == rank[y_parent])
        {
            rank[y_parent]+=1;
            parent[x_parent]=y_parent
        }

        else if(rank[x_parent] > rank[y_parent])
            //then x becomes the parent
            parent[y_parent]=x_parent
        
        else
            //then y becomes the parent
            parent[x_parent]=y_parent
    
    }
}


//DSU TEMPLATE FOR UNION AND FIND THROUGH OPTIMISED THAT IS AMMORTISED O(n) and is generally constant only some times it take O(n) to trace the root in the fnd operation

    vector<int> parent;
    vector<int> rank;
    int find(int val)
    {
        if (parent[val] == val)
            return val;

        return parent[val] = find(parent[val]);
    }

    void Union(int x, int y)
    {
        int parent1 = find(x);
        int parent2 = find(y);

        if (parent1 != parent2)
        {
            if (rank[parent1] == rank[parent2])
            {
                rank[parent2] += 1;
                // parent 2 becomes the new parent
                parent[parent1] = parent2;
            }

            else if (rank[parent1] > rank[parent2])
            {
                // parent 1 becomes the new parent
                parent[parent2] = parent1;
            }

            else
            {
                parent[parent1] = parent2;
            }
        }
    }

    //write in the int main at the top
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;  //all will be parent of themselves
        }

*/
int main()
{

    return 0;
}