#include <bits/stdc++.h>
using namespace std;
// Longest Univalue Path
/*
 int maxi = 0;

    int helper(TreeNode* root) {
        if (!root)
            return 0;

        int left = helper(root->left);
        int right = helper(root->right);


        if (root->left && root->left->val == root->val)
            left += 1; //MEANS IN SEQUENCE
        else
            left = 0; //SEQUENCE BREAKED SO RESET TO ZERO

        if (root->right && root->right->val == root->val)
            right += 1;
        else
            right = 0;

        maxi = max(maxi, left + right); //NOT DID LEFT+RIGHT+1 BECAUSE IN QUESTION THEY ARE NOT ASKIG TO TAKE THE
        //COUNT OF THE MID ELEMENT JUST ADD L + R HEIGHT


        Just think that i am standing on the root and have the left subtree
        height as well as the right subtree height just add that

        return max(left, right); //SENDING THE COUNT OF CONSECUTVENESS
        //THE MAX EQUI PATH WOULD BE SENT
    }
    int longestUnivaluePath(TreeNode* root) {
        helper(root);
        return maxi;
    }
*/
int main()
{

    return 0;
}