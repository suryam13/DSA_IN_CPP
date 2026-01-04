#include <bits/stdc++.h>
using namespace std;

/*
//TC-O(N)
    //SC-O(Log N) stack space
    void solve(TreeNode* root1, TreeNode* root2, int i) {
        if (!root1 && !root2)
            return;

        if (i & 1) // means odd
            swap(root1->val, root2->val);

        solve(root1->left, root2->right, i + 1);
        //conccurrently traversing opposite ends

        solve(root1->right, root2->left, i + 1);
        //reversed fashion so that each nodes child gets processed in reversed manner
    }
    TreeNode* reverseOddLevels(TreeNode* root) {

        int i = 1;
        //sending the left and right part of the main root
        solve(root->left, root->right, i);

        return root;
    }
*/
int main()
{

    return 0;
}