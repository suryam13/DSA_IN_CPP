#include <bits/stdc++.h>
using namespace std;
// vector<int> preorderTraversal(TreeNode *root)
// {

//     if (root == NULL)
//         return {};
//     // ROOT LEFT RIGHT --> PREORDER TRAVERSAL

//     vector<int> preOrder;

//     // IN STACK PUSH THE RIGHT FIRST THEN THE LEFT BECAUSE WE WANT TO DEAL WITH LEFT AND STACK FOLLOWS LIFO

//     stack<TreeNode *> st; // would store the ptr of NODES
//     st.push(root);

//     while (!st.empty())
//     {
//         TreeNode *temp = st.top();
//         st.pop();

//         // NOW THE PUSH THE RIGHT PART FIRST IF IT EXISTS
//         if (temp->right)
//             st.push(temp->right);

//         // NOW PUSH THE LEFT PART IF IT EXISTS
//         if (temp->left)
//             st.push(temp->left);

//         preOrder.push_back(temp->val);
//     }

//     return preOrder;
// }
int main()
{

    return 0;
}