#include<bits/stdc++.h>
using namespace std;
/*
optimised
O(3N) as each node is been visited three times in worst case
TreeNode* helper(vector<int>& preorder,int maxRange,int& i)
    {
        if(i>=preorder.size() || preorder[i] > maxRange)
        return NULL; //means the element cant be inserted here so return NULL

        TreeNode* root=new TreeNode(preorder[i]);
        i++;

        root->left=helper(preorder,root->val,i); //first left,maxRange would be the current val
        root->right=helper(preorder,maxRange,i); //then right

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {

        //using upper bound logic as preorder is root left right
        int i=0;
        return helper(preorder,INT_MAX,i);
        
    }
*/

/*
O(NlogN) due to sorting

//Same as construction of tree form inorder and preorder using codestory with mik method
    TreeNode* helper(vector<int>& preorder,vector<int>& inorder,int &i,int inStart,int inEnd,unordered_map<int,int> &inMap)
    {
        
        if(inStart>inEnd)
        return NULL;

        TreeNode* root=new TreeNode(preorder[i]);

        int posi=inMap[preorder[i]];
        i++;

        root->left = helper(preorder,inorder,i,inStart,posi-1,inMap);
        root->right=helper(preorder,inorder,i,posi+1,inEnd,inMap);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {

        //we know that if a tree is valid then the inorder would be the sorted values, now since we have 
        //inorder and preorder we can construct a tree
        
        vector<int> inorder(preorder.begin(),preorder.end());
        sort(inorder.begin(),inorder.end());

        unordered_map<int,int> inMap;

        for(int i=0;i<inorder.size();i++)
        {
            inMap[inorder[i]]=i;
        }
        int i=0;
        return helper(preorder,inorder,i,0,inorder.size()-1,inMap);
        
    }
*/
 int main()
{
    
    return 0;
}