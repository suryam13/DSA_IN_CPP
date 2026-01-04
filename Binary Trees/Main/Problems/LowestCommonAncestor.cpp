#include <bits/stdc++.h>
using namespace std;
// SHEET : LC-236
/*
TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || p == root || q == root) // means either NULL or p or q is found
            return root;

        TreeNode* left = helper(root->left, p, q);
        TreeNode* right = helper(root->right, p, q);

        if (left == NULL) // means right is one of the answer
            return right;

        else if (right == NULL) // means left is one of the answer
            return left;

        // NOTE that the case where both are NULL then NULL is been sent by the
        // if condition prior
        else
            return root; //--> means this is the LCA
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        return helper(root, p, q);
    }
*/
int main()
{

    return 0;
}