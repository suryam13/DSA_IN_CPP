#include<bits/stdc++.h>
using namespace std;

/*
Method 1 :

 //optimised approach O(logN) not considering that the tree is skew
    stack<TreeNode*> st;

    BSTIterator(TreeNode* root) {

        st.push(root);
        //as inorder follows L Root R,so go entire left after moving one right to continue the process
        auto topy=st.top();
        while(topy->left)
        {
            st.push(topy->left);
            topy=topy=topy->left;
        }

    }
    
    int next() {

        auto topy=st.top();
        st.pop();

        //if right exists then again go all possible left
        if(topy->right) {
        st.push(topy->right);

        auto insertAllleft=st.top(); //topy->right
        while(insertAllleft->left)
        {
            st.push(insertAllleft->left);
            insertAllleft=insertAllleft->left;
        }}
        return topy->val;
        
    }
    
    bool hasNext() {
        return !st.empty(); //if stack has elements means true
        
    }
*/

/*
Method 2 : 
 // usual method by storing the inorder traversal and traversing throughout takes O(N) space and O(1) operation for next and has next(ammortized means average cost per operation over multiple oprerations) 

    vector<int> inorder;
    int i = 0;

    void helper(TreeNode* root) {
        if (!root)
            return;

        helper(root->left);
        inorder.push_back(root->val);
        helper(root->right);
    }
    BSTIterator(TreeNode* root) { helper(root); }

    int next() { return inorder[i++]; }

    bool hasNext() { return (i < inorder.size()); }
*/
 int main()
{
    
    return 0;
}