#include <bits/stdc++.h>
using namespace std;

//SHEET : CODING NINJAS
// vector<vector<int>> getTreeTraversal(TreeNode *root)
// {
//     vector<int> pre, post, ino;
//     vector<vector<int>> ans;

//     stack<pair<TreeNode *, int>> st; // second will store the count

//     st.push(make_pair(root, 1)); // push the initial one

//     while (!st.empty())
//     {
//         auto it = st.top();
//         st.pop();

//         // preOrder RootLR
//         if (it.second == 1) // add to pre and increment and check if left exists then add
//         {
//             pre.push_back(it.first->data);
//             st.push(make_pair(it.first, it.second + 1));

//             if (it.first->left) // if not null
//                 st.push(make_pair(it.first->left, 1));
//         }

//         // inOrder
//         else if (it.second == 2) // add to post and increment
//         {
//             ino.push_back(it.first->data);
//             st.push(make_pair(it.first, it.second + 1));

//             if (it.first->right) // if not null
//                 st.push(make_pair(it.first->right, 1));
//         }

//         // post
//         // just push back
//         else
//         {
//             post.push_back(it.first->data);
//         }
//     }
//     ans.push_back(ino);
//     ans.push_back(pre);
//     ans.push_back(post);
//     return ans;
// }
int main()
{

    return 0;
}