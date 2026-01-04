#include <bits/stdc++.h>
using namespace std;

// SHEET : LC-701

/*
Try to figure out at which leaf is it possible to place
Recursive Approach
 TreeNode* attach(TreeNode* root, int val) {
        if (!root)
            return NULL;

        if (root->val > val) // means left
        {  
            if (attach(root->left, val) == NULL) // means attach  
            {
                TreeNode* temp = new TreeNode(val);
                root->left = temp;
            }
            return root;
        }

        else { // means right

            if (attach(root->right, val) == NULL) // means attach
            {
                TreeNode* temp = new TreeNode(val);
                root->right = temp;
            }
            return root;
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) {
            TreeNode* temp = new TreeNode(val);
            return temp;
        }

        attach(root,val); //would attach automatically
        return root;
    }

*/

/*
Iterative Approach
TreeNode* insertIntoBST(TreeNode* root, int val) {

        // iterative approach O(1) space

        if(!root)
        {
            TreeNode* newNode = new TreeNode(val);
            return newNode;
        }

        TreeNode* temp;
        TreeNode* mover = root;

            while (mover) {
            if (mover->val > val) // go left
            {
                if (!mover->left) temp = mover;
                // update temp so that we can store at which
                // root val is to be inserted
                mover = mover->left;
            }

            else // right side
            {
                if (!mover->right) temp = mover;
                // update temp so that we can store at which
                // root val is to be inserted
                mover = mover->right;
            }
        }

        TreeNode* newNode = new TreeNode(val);
        if (temp->val > val)
            temp->left = newNode;

        else
            temp->right = newNode;

        return root;
    }
*/
int main()
{

    return 0;
}