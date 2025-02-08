#include <bits/stdc++.h>
using namespace std;

//SHEET : LC-987
// map<int, vector<pair<int, int>>> mapy; // j corresponding elements which are on same y axis inside pair{i,j} where i represents
// // the x-axis if elements appear on same x-axis then sort in ascending order

// void helper(TreeNode *root, int i, int j)
// {
//     if (!root) // means NULL
//         return;

//     helper(root->left, i + 1, j - 1);
//     helper(root->right, i + 1, j + 1);
//     mapy[j].push_back({i, root->val});
// }
// vector<vector<int>> verticalTraversal(TreeNode *root)
// {

//     vector<vector<int>> ans;
//     helper(root, 0, 0);

//     auto comp = [](pair<int, int> p1, pair<int, int> p2)
//     {
//         if (p1.first == p2.first)
//             return p1.second < p2.second; // sort in ascending order means pehle smaller value aayega

//         else
//             return p1.first < p2.first; // else earlier p1 should be there then p2 as they are not same maintain y-axis order
//     };

//     for (auto &it : mapy)
//     {
//         auto vec = mapy[it.first];          // now this contains pairs
//         sort(vec.begin(), vec.end(), comp); // sorted as per requirement

//         vector<int> yes;
//         for (auto it : vec)
//             yes.push_back(it.second);

//         ans.push_back(yes);
//     }

//     return ans;
// }
int main()
{

    return 0;
}