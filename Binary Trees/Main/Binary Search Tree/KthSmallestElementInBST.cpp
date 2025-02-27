#include<bits/stdc++.h>
using namespace std;

/*
 void helper(TreeNode* root,int k,int &posi,int &ans)
    {
        if(!root || posi>k) //if posi>k means element found
        return;

        helper(root->left,k,posi,ans);
          
        if(posi==k) ans=root->val;
        ++posi;

        helper(root->right,k,posi,ans);    
    }
    
    int kthSmallest(TreeNode* root, int k) {

        //since the inorder traversal of a BST is in a sorted manner we can easily compare with that
        //as the 1st smallest would be on the 1st position

        //left root right

        int ans;
        int posi=1;
        helper(root,k,posi,ans);
        return ans;


        //if kth largest is to be found then do reverse inorder
        /*
        void helper(TreeNode* root,int k,int &posi,int &ans)
        {
        if(!root || posi>k) //if posi>k means element found
        return;

        helper(root->right,k,posi,ans);

        if(posi==k) ans=root->val;
        ++posi;

        helper(root->left,k,posi,ans);
        }
        */
       
 int main()
{
    
    return 0;
}