#include <bits/stdc++.h>
using namespace std;

// SHEET : LC - 700
// TC : since it is a bst it would take O(logN) in worst case(skew tree) would take O(N)

/*
Recursive Approach
TC- O(log N)
Sc-O(logN) recursion stack space
  TreeNode* helper(TreeNode* root,int target)
    {
        if(!root) //if null
        return NULL;

        if (root->val==target)
        return root;

        if(target>root->val) //then move to  right subtree
        return  helper(root->right,target);

        else //move to left subtree
        return helper(root->left,target);

        return NULL;
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        return helper(root,val);
    }


*/

/*
Iterative
TC- O(log N)
Sc-O(1) no stack space

        while(root!=NULL  && root->val!=val)
        {
            if(root->val < val)
            root=root->right;

            else
            root=root->left;
        }
        return root;
*/
int main()
{

    return 0;
}