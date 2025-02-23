#include <bits/stdc++.h>
using namespace std;

/*
 int getNum(string& traversal, int& ind) {
        int i = ind;
        while (true) {
            if (ind < traversal.size() && isdigit(traversal[ind]))
                ind++;

            else
                break;
        }

        int val = stoi(traversal.substr(i, ind - i));
        --ind;
        return val;
    }

    bool helper1(int cntDash, int num, TreeNode* root) // for left side
    {
        if (cntDash == 0) {
            if (!root->left) {
                // can insert
                TreeNode* nody = new TreeNode(num);
                root->left = nody;
                return true;
            }

            else if (!root->right) {
                // can insert
                TreeNode* nody = new TreeNode(num);
                root->right = nody;
                return true;
            }

            else // means it has to be on the right side
                return false;
        }

        if (root->left && helper2(cntDash - 1, num, root->left))
            return true;

        if (root->right && helper2(cntDash - 1, num, root->right))
            return true;

        return false;
    }

    bool helper2(int cntDash, int num, TreeNode* root) // for left side
    {
        if (cntDash == 0) {
            if (!root->left) {
                // can insert
                TreeNode* nody = new TreeNode(num);
                root->left = nody;
                return true;
            }

            else if (!root->right) {
                // can insert
                TreeNode* nody = new TreeNode(num);
                root->right = nody;
                return true;
            }

            else // means it has to be on the right side
                return false;
        }

        if (root->right && helper2(cntDash - 1, num, root->right))
            return true;

        if (root->left && helper2(cntDash - 1, num, root->left))
            return true;

        return false;
    }

    TreeNode* recoverFromPreorder(string traversal) {

        int cntDash = 0;
        bool check = false;

        // finding the root value as it could be multiple digits
        int j = 0;
        while (true) {
            if (isdigit(traversal[j]))
                j++;

            else
                break;
        }

        int val = stoi(traversal.substr(0, j));

        TreeNode* root = new TreeNode(val);
        // cout << root->val;
        // cout<<j;
        for (int i = j; i < traversal.size(); i++) {
            if (traversal[i] == '-')
                cntDash++;

            else {

                if (cntDash == 1 && root->left)
                    check = true;
                int toSend = getNum(traversal, i);

                cout << toSend << " " << cntDash << " " << i << endl;

                if (check == false) {
                    if (helper1(cntDash - 1, toSend, root)) {
                        cntDash = 0;
                        continue;
                    }
                }

                else
                    helper2(cntDash - 1, toSend, root);

                cntDash = 0;
            }
        }

        return root;
    }
*/
int main()
{

    return 0;
}