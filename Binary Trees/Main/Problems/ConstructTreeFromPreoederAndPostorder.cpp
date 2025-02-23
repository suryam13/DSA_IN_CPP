#include<bits/stdc++.h>
using namespace std;
//LC-889
/*
TreeNode* helper(vector<int>& preorder, vector<int>& postorder,int preStart, int preEnd, int postStart, int postEnd,unordered_map<int, int>& mapy) {
        if(preStart>preEnd)
        return NULL;  //if any of them exceeds then return NULL

        TreeNode* root = new TreeNode(preorder[preStart]);
        if (preStart == preEnd) //means only 1 element in preorder so cant run for preOrder+1 which is expected to be left
        // child
        return root;

       
        int currPos = mapy[preorder[preStart + 1]]; // distance of left element in postorder stored in map 
        int leftDist = currPos - postStart + 1; //counting the number of elements to the left


        //making partition and solving independently through recursion
        root->left = helper(preorder, postorder, preStart + 1, preStart + leftDist,postStart,currPos, mapy);
        root->right = helper(preorder, postorder, preStart + leftDist + 1,preEnd, currPos + 1, postEnd - 1, mapy);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder,vector<int>& postorder) {

        // store the values of postorder in map;
        int n = preorder.size();
        unordered_map<int, int> mapy;

        for (int i = 0; i < postorder.size(); i++) {
            mapy[postorder[i]] = i;
        }

        return helper(preorder, postorder, 0, n - 1, 0, n - 1, mapy);
    }
*/
 int main()
{
    
    return 0;
}