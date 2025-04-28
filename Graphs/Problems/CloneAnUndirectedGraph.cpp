#include <bits/stdc++.h>
using namespace std;

// GFG
/*
 void dfs(Node* u,  unordered_map<int,Node*> &mapy,Node* node)
    {
        mapy[u->val]=u;

         for (auto neighbor : node->neighbors) {


            if(mapy.find(neighbor->val) != mapy.end())
            //means exists,means visited,so dont explore further,just push the edge
            u->neighbors.push_back(mapy[neighbor->val]);


            else  //not visited so give a dfs
           {
             Node *neighby=new Node(neighbor->val); //create a new node
             u->neighbors.push_back(neighby);

             dfs(neighby,mapy,neighbor);
           }
        }
    }
    Node* cloneGraph(Node* node) {


        //would be given reference nod

        unordered_map<int,Node*>mapy; //to store the pointer to corresponding new value
        if(!node) return NULL;

        Node *head = new Node(node->val);

        dfs(head,mapy,node);

        return head;
    }
*/
int main()
{

    return 0;
}