#include <bits/stdc++.h>
using namespace std;

// Two Stacks
//  vector<int> postorderTraversal(TreeNode *root)
//  {
//      if (!root)
//          return {};
//      // LEFT RIGHT ROOT
//      vector<int> postOrder;

//     stack<TreeNode *> st1; // Pushing left first then right
//     stack<TreeNode *> st2; // Storing Top Elements of another

//     st1.push(root);

//     while (!st1.empty())
//     {
//         // get the top element
//         TreeNode *temp = st1.top();
//         st1.pop();

//         // push the current top to next stack
//         st2.push(temp);

//         if (temp->left)
//             st1.push(temp->left); // if exists then push left one
//         if (temp->right)
//             st1.push(temp->right); // if exists then push the right one
//     }

//     while (!st2.empty())
//     {
//         postOrder.push_back(st2.top()->val);
//         st2.pop();
//     }
//     return postOrder;
// }

// Method 2:
/* vector<int> postOrder(Node* node) {
        vector<int> ans;

        stack<Node*> st;
        st.push(node);

        while(!st.empty())
        {

             Node* temp= st.top();
            st.pop();


            if(temp->left)st.push(temp->left);
            if(temp->right)st.push(temp->right);

            ans.push_back(temp->data);

        }

        reverse(ans.begin(),ans.end());
        return ans;
    } */
int main()
{

    return 0;
}