#include <bits/stdc++.h>
using namespace std;
// SHEET : LC - 124

// MY APPROACH
/*
 int maxi = INT_MIN;

    int helper(TreeNode* root) {
        if (!root) // simply return 0 if null
            return 0;

        int left = helper(root->left);
        int right = helper(root->right);

        int toBeSent;
        if (right > left)
            toBeSent = right + root->val;

        else
            toBeSent = left + root->val;

        maxi = max({maxi, left + root->val + right});

        if (toBeSent < 0) // if -ve then please send 0 as it wont be
                          // contributing in maximum
            return 0;

        return toBeSent;
    }
    int maxPathSum(TreeNode* root) {
        if (!root)
            return 0;
        helper(root);
        return maxi;
    }
*/
 
// ANOTHER APPRAOCH
/*
 int maxi = INT_MIN;

    int helper(TreeNode* root) {
        if (!root) // simply return 0 if null ;
            return 0;

        int left = max(0,helper(root->left)); //ignoring -ve here itself
        int right = max(0,helper(root->right));

        maxi = max({maxi, left + root->val + right});

        return root->val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        if (!root) return 0;
        helper(root);
        return maxi;
    }
 */
int main()
{

    return 0;
}