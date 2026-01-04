#include <bits/stdc++.h>
using namespace std;
//SHEET LC-102
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> levelOrder(TreeNode *root)
{
    if (root == NULL)
        return {};

    // firstly we will require a queue to store the root values at each level
    queue<TreeNode *> q;

    vector<vector<int>> ans; // to store the vector of values at each level

    q.push(root); // pushing the root address first in the queue

    while (!q.empty())
    {
        int size = q.size(); // initially store the size of the queue so as to do the operation for that many elements
        vector<int> v;
        for (int i = 0; i < size; i++)
        {
            TreeNode *temp = q.front();
            q.pop();

            if (temp->left)
                q.push(temp->left);
            // if left node exists then push that
            if (temp->right)
                q.push(temp->right);
            // if right node exists then push that

            v.push_back(temp->val);
        }
        ans.push_back(v);
    }
    return ans;
}
int main()
{

    return 0;
}