#include<bits/stdc++.h>
using namespace std;
/*
For postorder just replace right with left and vice verca and at last just reverse the ans
Explanation :

The Preorder goes like : Root Left Right 

so means when standing on a root we want the route back to the root when the left part is explored so before moving to left we have to ensure that the threading of the rightmost is been done to the current root 

Case 1: 
Suppose if the left doesnt exist standing on a root means the current one is the only root possible so directly go to next parameter in Preorder which is right

Case 2: If left exists then please go to extreme right possible and thread to root and push the root 

case 3: if threaded then unthread
*/
vector<int> inOrder;

void preorderMorris()
{
    TreeNode* curr=root; //root of the tree

    while(!curr)
    {   
        if(!curr->left) //means NULL
        {
            //since curr is the only possible root at this instant 
            inOrder.push_back(curr->val);
            curr=curr->right;
        }

        else //means left exists so map or make thread the rightmost in the left part print curr first and then move to left as it is Root first in Preorder.
        {   
            TreeNode* temp=curr->left;

            //means both the conditions should be satisfied that is keep moving and temp->right should not be null and the temp->right should not be pointing to curr,if it is means it was been threaded earlier so now delete the thread 
            while(temp->right && temp->right!=curr)
            {
                temp=temp->right;
            }

            //if it comes out of the loop there would propably be one reason resulting in to be false;

            if(!temp->right) //means it is NULL means unmapped/unthreaded so make a thread and push the root here only
            {
                temp->right=curr;
                inOrder.push_back(curr->val);
                //now curr can easily come to left as mapping is been done and the root is been pushed as it is Preorder so root first
                curr=curr->left;
            }

            else //means it is threaded
            {
                //since threaded means now the root is reached so unthread and then move to right 
                temp->right=NULL;
                curr=curr->right;

            }
        }

    }
}
 int main()
{
    
    return 0;
}