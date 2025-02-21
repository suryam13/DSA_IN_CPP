#include <bits/stdc++.h>
using namespace std;
// SHEET : GFG
/*
class Solution {
  public:

    Node* value;
    void search(Node* root,int target)
    {
        if(!root)
        return;

        if(root->data==target)
        value=root;

        search(root->left,target);
        search(root->right,target);

    }

    void markParents(Node* root,unordered_map<Node*,Node*> &parent_track)
    {
            queue<Node*> q;
            q.push(root);

            while(!q.empty())
            {
                int size=q.size();
                int i=0;

                while(i<size)
                {
                    auto top=q.front();
                    q.pop();

                    if(top->left)
                    {
                        parent_track[top->left]=top;
                        q.push(top->left);
                    }

                     if(top->right)
                    {
                        parent_track[top->right]=top;
                        q.push(top->right);
                    }

                    i++;
                }
            }
    }

    int minTime(Node* root, int target) {
        //as i have to traverse to the upper side i will have to find the parent
        //as it is easy to find left right but for traversing up we need to go to the
        //parent

        //finding where is the target
        search(root,target);

        unordered_map<Node*,Node*> parent_track;
        markParents(root,parent_track);


        unordered_map<Node*,bool> visited; //to keep track of the visited ones so that
        //i dont go radially outwards over there again

        int cnt=0;

        queue<Node*> q;
        q.push(value);
        visited[value]=true;


        while(!q.empty())
        {
            int size=q.size();
            cnt++;

            int i=0;
            while(i<size)
            {
                auto top=q.front();
                q.pop();

                 if(top->left && !visited[top->left])
                {
                    q.push(top->left);
                    visited[top->left]=true;
                }

                  if(top->right && !visited[top->right])
                {
                    q.push(top->right);
                    visited[top->right]=true;
                }

                //checking whether the above one is marked or not that is the parent,this was the reason why we made parent
                if(parent_track[top] && !visited[parent_track[top]])
                {
                    q.push(parent_track[top]);
                    visited[parent_track[top]]=true;
                }
                i++;
            }
        }
        return cnt-1;

        return 0;

    }

*/
int main()
{

    return 0;
}