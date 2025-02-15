#include <bits/stdc++.h>
using namespace std;
//Simplified way to solve is using level order traversal(bfs)

// // note it wont work if i just take the vertical in dfs because suppose if
// // 2,0 comes after the left traversal then it will take the place on vertical 0
// map<int, pair<int, int>> mapy; // vertical level value at node

// // i is vertical and j is level
// void helper(Node *root, int i, int j)
// {
//     if (!root)
//         return;

//     // if its empty or the prior stored is lesser level than the current
//     // equal to check so as to ensure that the right most is taken
//     if (mapy.find(i) == mapy.end() || mapy[i].first <= j)
//         mapy[i] = {j, root->data};

//     helper(root->left, i - 1, j + 1);
//     helper(root->right, i + 1, j + 1);
// }

// vector<int> bottomView(Node *root)
// {
//     vector<int> ans;

//     if (!root)
//         return ans;

//     helper(root, 0, 0);

//     for (auto it : mapy)
//     {
//         ans.push_back(it.second.second);
//     }

//     return ans;
// }
int main()
{

    return 0;
}