#include <bits/stdc++.h>
using namespace std;
// SHEET : LC-222
/*
O(N) Solution
 int cnt = 0;
    void helper(TreeNode* root) {
        if (!root)
            return;

        cnt++;
        helper(root->left);
        helper(root->right);
    }
    int countNodes(TreeNode* root) {

        helper(root);
        return cnt;
    }
*/

/*
    T.C. (logN)^2

   int helper(TreeNode* root) {
    if (!root)
        return 0;

    int lh = countL(root);
    int rh = countR(root);

    if (lh == rh)
        return (1 << lh) - 1; shortcut for calcualting the poer 1<<2

    return 1 + helper(root->left) + helper(root->right); //
}

int countL(TreeNode* root) {
    int h = 0;

    while (root) {
        h++;
        root = root->left;
    }
    return h;
}

int countR(TreeNode* root) {
    int h = 0;

    while (root) {
        h++;
        root = root->right;
    }
    return h;
}

int countNodes(TreeNode* root) { return helper(root); }

*/
int main()
{

    return 0;
}