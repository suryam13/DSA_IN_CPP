#include <bits/stdc++.h>
using namespace std;

// In the previous code base we studied about euler graph which exists when there is both eulerian path and eulerian circuit as well.

/*
A short recap of Euler Graph :

UDG:
When all the degrees are even and 2 of the vertices have odd degree then we say it to have eulerian path
When all of the edges have even degree then we can say the graph has eulerian circuit.

DG:
When all the nodes have equal inDegree and OutDegree and two of the vertices have the difference as 1 then eulerian path
SRC => OutDegree - InDegree = 1
DEST => InDegree - OutDegree =1
When all of the edges have same outDegree and inDegree then we can say the graph has eulerian circuit.

Now to find the eulerian path we use Heirholzers Algo :

CODE :
//LC 2097
 vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {

        //This question talks about a sequence means it would start at some point and would end at some point
        //and the edge wont be repeating so it kind of gives a hint for eulerian graph we just have to find the
        //starting point in this directed graph
        unordered_map<int,vector<int>> adj;
        unordered_map<int,int> inDegree,outDegree;

        for(auto & pair:pairs)
        {
            adj[pair[0]].push_back(pair[1]);
            //also calculate the inDegree and OutDegree
            inDegree[pair[1]]++;
            outDegree[pair[0]]++;
        }

        //now calculate which is the starting point of this eulerian graph
        cout<<outDegree[1];
        int startPoint=pairs[0][0]; //in case eulerian circuit then we can take any of the node
        for(auto &[key,value]:adj)
        {
            if(outDegree[key] - inDegree[key] == 1)
            {
                startPoint=key;
                break;
            }
        }

        //we've got the start point now finding the euler path
        //we pop from the back of the vector because it is efficient and takes constant time
        
        vector<int> path;
        stack<int> st;
        st.push(startPoint);
        while(!st.empty())
        {
            int top=st.top();

            if(!adj[top].empty())
            {
                st.push(adj[top].back());
                adj[top].pop_back();
            }

            else
            {
                path.push_back(top);
                st.pop();
            }
        }

        reverse(path.begin(),path.end());
        cout<<startPoint;
        vector<vector<int>> ans;
        //now making pairs
        for(int i=0;i<path.size()-1;i++)
        {
            ans.push_back({path[i],path[i+1]});
        }

        return ans;

    }

*/
int main()
{

    return 0;
}