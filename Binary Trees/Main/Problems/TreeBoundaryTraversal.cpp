#include <bits/stdc++.h>
using namespace std;
// SHEET : GFG

//ANTICLOCKWISE
// vector<int> ans;
// bool leafNode(Node *root)
// {
//     if (!root->left && !root->right)
//         return true;

//     return false;
// }
// void leftboundary(Node *root)
// {
//     // go left as far as possible if not then right dont visit leaf nodes

//     Node *temp = root->left;

//     while (temp)
//     {
//         if (!leafNode(temp))
//             ans.push_back(temp->data);

//         if (temp->left)
//             temp = temp->left;

//         else
//             temp = temp->right;
//     }
// }

// void rightboundary(Node *root)
// {
//     Node *temp = root->right;
//     // here we have to store the right part in reverse order so using stack
//     // to add in the answer at last

//     stack<int> dummy;
//     while (temp)
//     {
//         if (!leafNode(temp))
//             dummy.push(temp->data);

//         if (temp->right)
//             temp = temp->right;

//         else
//             temp = temp->left;
//     }

//     while (dummy.size())
//     {
//         ans.push_back(dummy.top());
//         dummy.pop();
//     }
// }

// void addLeafnodes(Node *root)
// {

//     if (leafNode(root))
//         ans.push_back(root->data);

//     if (root->left)
//         addLeafnodes(root->left);

//     if (root->right)
//         addLeafnodes(root->right);
// }
// vector<int> boundaryTraversal(Node *root)
// {

//     if (!root) // means null
//         return {};

//     if (!leafNode(root))
//         ans.push_back(root->data);
//     // first we will consider the left part
//     leftboundary(root);
//     addLeafnodes(root);
//     rightboundary(root);

//     return ans;
// }
int main()
{

    return 0;
}