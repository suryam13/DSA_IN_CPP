#include <bits/stdc++.h>
using namespace std;
/*
bool helper(TreeNode* root,int &prev,bool &check)
    {
        if(!root)
        return true;

        if(!helper(root->left,prev,check))
        return false;

        if(check && root->val <= prev) //means the ascending order is been distorted adding = to check
        //duplicates if yes then its same and BST cannot contain same element so return false
        return false;

        else if(!check) //means prev is empty and the first element needs to be entered
        {
            check=true;
            prev=root->val;
        }

        else prev=root->val;//everything is alright so just store the prev

        if(!helper(root->right,prev,check))
        return false;

        return true;
    }
    bool isValidBST(TreeNode* root) {
        bool check=false;
        int prev;
        return helper(root,prev,check);

        //either can take long min to avoid usage of flag
        //another appraoch is to provide ranges,start with INT_MIN and INT_MAX for root and then for left
        //side the range would shrink between INT_MIN and the root and for right side the range would be
        //root->val to INT_MAX then for the consequent elements apply the same logic for-eg after going
        //left then moving right the range would pe parent value to root value do it recursively


    }
*/
int main()
{

    return 0;
}