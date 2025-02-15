#include <bits/stdc++.h>
using namespace std;

/*
 vector<int> ans;

    // unordered_set<int> st; //to keep track of levels

    void helper(TreeNode* root,int i)
    {
        if(!root)
        return;

        // if(st.find(i)==st.end())  //then only take that specified level if no one is taken at rightmost
        // ans.push_back(root->val);

        // st.insert(i); //keep track of levels taken
        //smart technique to not use set and use this logic instead
        if(i==ans.size()) //means on this level no one has been added
        ans.push_back(root->val);


        //call for right first
        helper(root->right,i+1);

        helper(root->left,i+1);
    }

    vector<int> rightSideView(TreeNode* root) {

        if(!root) return{};

        helper(root,0);

        return ans;

    };
*/
int main()
{

    return 0;
}