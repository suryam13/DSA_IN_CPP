#include<bits/stdc++.h>
using namespace std;

/*
  TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(!root)
        return NULL;

        //these cases would also cover the self descendant case as it wont strictly follow the first two
        //conditions so would end up returning the root itself
        if( root->val > p->val && root->val > q->val)
        return helper(root->left,p,q);

        else if( root->val < p->val && root->val < q->val)
        return helper(root->right,p,q);

        else  //since both lies on opposite ends
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //the concept is that in a BST if the paths get split means the p value and q value are on
        //either sides means the cuurent root would be the LCA as the paths got split over here!

        return helper(root,p,q);
    }
*/
 int main()
{
    
    return 0;
}