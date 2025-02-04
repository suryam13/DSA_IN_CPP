#include <bits/stdc++.h>
using namespace std;

// SHEET : LC-104

// Another method is using queue that is level order traversal
//  // int cnt=0;
//  // void helper(TreeNode* root,int i)
//  // {   if(root==NULL)
//  //     {
//  //         cnt=max(cnt,i);
//  //         return;
//  //     }

// //     helper(root->left,i+1); //go to left
// //     helper(root->right,i+1); //go to right
// // }

// int helper(TreeNode *root)
// {
//     if (root == NULL)
//         return 0;

//     int left = 1 + helper(root->left);
//     int right = 1 + helper(root->right);

//     return max(left, right);
// }

// int maxDepth(TreeNode *root)
// {

//     // helper(root,0);
//     // return cnt;

//     /*Method 2*/

//     return helper(root);
// }
int main()
{

    return 0;
}