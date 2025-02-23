#include <bits/stdc++.h>
using namespace std;
// LC : 297

/* stringstream takes a tc on average O(n) as we are inserting entire string into that 
 // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        // level order traversal
        string serialized;

        if (!root)
            return "";

        queue<TreeNode*> q;
        q.push(root);

        serialized.append(to_string(root->val) + ',');
        // doing this as there can be two digits nums too,so seperating
        // it with trailing commas

        while (!q.empty()) {
            TreeNode* top = q.front();
            q.pop();

            if (top->left) // exists
            {
                q.push(top->left);
                serialized.append(to_string(top->left->val) + ',');
            }

            else
                serialized.append("N,"); // null so push N

            if (top->right) // exists
            {
                q.push(top->right);
                serialized.append(to_string(top->right->val) + ',');
            }

            else
                serialized.append("N,"); // null so push N
        }

        return serialized;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        // i need to extract each of the number seperated by commas so will be
        // using stringstream
        if (data.size() == 0)
            return NULL;

        stringstream ss(data);
        string num;

        queue<TreeNode*> q;
        int i = 1; //the traversal in v starts are from as the correspondants would be left and right

        vector<string> v; // for storing the numbers to keep it ease

        while (getline(ss, num, ',')) // store values in vector
            v.push_back(num);


        // for (auto it : v)
        //     cout << it << " ";

        TreeNode* root = new TreeNode(stoi(v[0]));
        q.push(root);

        //OR while(i<v.size())
        while (!q.empty()) {
            TreeNode* top = q.front();
            q.pop();

            TreeNode* lefty = new TreeNode();
            if (v[i] == "N") // means the left part is NULL
            {
                lefty = NULL;
            } else {
                // some number
                lefty->val = stoi(v[i]);
                q.push(lefty);
            }

            i++;
            TreeNode* righty = new TreeNode();
            if (v[i] == "N") // means the right part is NULL
            {
                righty = NULL;
            } else {
                // some number
                righty->val = stoi(v[i]);
                q.push(righty);
            }
            i++;

            top->left = lefty;
            top->right = righty;
            //attach the values to root
        }
        return root;
    }
*/
int main()
{

    return 0;
}