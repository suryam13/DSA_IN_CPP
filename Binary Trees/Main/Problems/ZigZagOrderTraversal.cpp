#include <bits/stdc++.h>
using namespace std;

// SHEET : LC-103
//   vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//              if(!root) //means null
//              return {};

//           vector<vector<int>> ans;

//           queue<TreeNode*> q; //same as level order traversal with minor tweaks
//           bool check=1; //the first level should not be reversed thats why
//           q.push(root);

//           while(!q.empty())
//           {
//                 int size=q.size();
//                 vector<int> dummy;
//                 while(size--)
//                 {
//                     TreeNode* top=q.front();
//                     q.pop();

//                     if(top->left)  q.push(top->left);
//                     if(top->right) q.push(top->right);

//                     dummy.push_back(top->val);
//                 }
//                 if(!check) //means the dummy has to be reversed to maintain the zigzag order
//                 {
//                     check=1;
//                     reverse(dummy.begin(),dummy.end());
//                 }

//                 else check=0; //just to maaintain the consecutiveness of zigzag traversal

//                 ans.push_back(dummy);
//           }
//           return ans;

//     }
int main()
{

    return 0;
}