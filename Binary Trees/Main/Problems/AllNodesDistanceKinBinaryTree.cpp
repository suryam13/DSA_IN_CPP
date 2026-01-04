#include <bits/stdc++.h>
using namespace std;
// SHEET : LC-863

/*
  //to store the parent of each child doing level order traversal
    void markParents(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parent_track)
    {
            queue<TreeNode*> q;
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


    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        //as i have to traverse upside too i'll have to mark parents to get to know
        unordered_map<TreeNode*,TreeNode*> parent_track; //child -> parent
        markParents(root,parent_track);

        unordered_map<TreeNode*,bool> visited; //to keep track of the visited ones so that
        //i dont go radially outwards over there again

        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;

        int level=0;

        while(!q.empty())
        {
            int size=q.size();
            int i=0;
            level++;
            if(level>k)
            break; //as we have got the required distance elements

            while(i<size)
            {
                auto top=q.front();
                q.pop();

                //if left exists and it isn't visited
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

        vector<int> ans;
        //the queue now contains the required distance values

        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
 */
int main()
{

    return 0;
}