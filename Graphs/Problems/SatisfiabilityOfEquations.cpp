#include <bits/stdc++.h>
using namespace std;
/*
INTUTUION : 
GOT TO KNOW THAT WE HAVE TO MAKE INDIVIDUAL SETS AND GROUP THEM AS COMPONENTS,SO FIRST GROUP ALL THE COMPONENTS i.e. '=' AND THEN CHECK FOR THE UNEQUAL ONES IF THEY BELONG TO THE SAME LEADER MEANS THEY ARE EQUIVALENT AND THIS CONDITON IS FALSE i.e a!=a 

*/
// LC 990
class Solution
{
public:
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
    bool equationsPossible(vector<string> &equations)
    {

        /*
        First try to find all the unions and then go for the find operation
        which is in the case of != as, because if we do it concuurently then relation might not be dealt
        eg :  "a==b","b!=c","c==a"]
        */

        parent.resize(26);
        rank.resize(26, 0);

        for (int i = 0; i < 26; i++)
        {
            parent[i] = i; // all will be parent of themselves
        }

        for (auto &eq : equations)
        {
            if (eq[1] == '=')                    // union
                Union(eq[0] - 'a', eq[3] - 'a'); // send as integers as above all the operations ar done with respect to int
        }

        for (auto &eq : equations)
        {
            if (eq[1] == '!') // find
            {
                int find1 = find(eq[0] - 'a'); // do int conversion
                int find2 = find(eq[3] - 'a');

                if (find1 == find2) // if parents are same means a!=a means false
                    return false;
            }
        }

        return true;
    }
};
int main()
{

    return 0;
}