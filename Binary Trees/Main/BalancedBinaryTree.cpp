#include <bits/stdc++.h>
using namespace std;
//SHEET : LC-110

//Method 1
// int helper(TreeNode *root)
// {
//     if (!root)
//         return 0;

//     int left = helper(root->left); // returning the left side height
//     if (left == -1)
//         return -1;
//     int right = helper(root->right); // returning the right side height
//     if (right == -1)
//         return -1;

//     if (abs(left - right) > 1)
//         return -1;
//     // if at any moment the abs appears to be -1 then all functions would be immediately returning -1 step by step
//     // without any further calls been made;
//     return max(left, right) + 1; // returning the height as usual of the tree
// }

// bool isBalanced(TreeNode *root)
// {

//     if (!root) // NULL
//         return true;

//     if (helper(root) == -1)
//         return false; // false

//     return true; // true if not -1
// }

/*Method 2 */
//    int height(TreeNode* root) {
//         if (!root)
//             return true;

//         int left = height(root->left);
//         int right = height(root->right);

//         return max(left, right) + 1;
//     }

//     bool check(TreeNode* root) {
//         if (!root) // NULL
//             return true;

//         int leftH = height(root->left);
//         int rightH = height(root->right);

//         if (abs(leftH - rightH) > 1)
//             return false;

//         bool left = check(root->left);
//         if (!left)
//             return false;
//         bool right = check(root->right);
//         if (!right)
//             return false;

//         return true;
//     }

//     bool isBalanced(TreeNode* root) {

//         if (!root)
//             return 1;

//         return check(root);
//         return true; // true if not -1
//     }
int main()
{

    return 0;
}