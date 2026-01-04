#include <bits/stdc++.h>
using namespace std;
/*
  //another approach is to simply store the inorder and then and traverse using pointeres at end
    //TC O(N) W.C.  SC O(N)

    stack<TreeNode*> st1;//left half
    stack<TreeNode*> st2;//right half

    bool findTarget(TreeNode* root, int k) {

        //inorder kind of optimal storage
        st1.push(root);
        auto topy1=st1.top();
        while(topy1->left)
        {
            st1.push(topy1->left);
            topy1=topy1->left;
        }

        //reverse inorder kind of optimal storage
        st2.push(root);
        auto topy2=st2.top();
        while(topy2->right)
        {
            st2.push(topy2->right);
            topy2=topy2->right;
        }



        while(st1.top()->val != st2.top()->val) //if equal means they are pointing to same number
        {

        auto top1=st1.top()->val;
        auto top2=st2.top()->val;

        if(top1+top2 == k)
        return true;

        else if(top1+top2 > k) // means shrink the st2
        {
            //we have to do reverse inorder in this part to get the answers in descending manner so one
            //left then traverse all right same as opposite of st1 as we have to go R root L in this
            auto topy2=st2.top();
            st2.pop();

            if(topy2->left)
            {
                st2.push(topy2->left);

                auto top=st2.top(); //topy2->left,now traverse all right possible

                while(top->right)
                {
                    st2.push(top->right);
                    top=top->right;
                }
            }
        }

        else //means shrink the st1 as the cumulative sum is smaller
        {
            auto topy1=st1.top();
            st1.pop();

            if(topy1->right)
            {
                st1.push(topy1->right);

                auto top=st1.top(); //topy1->right,now traverse all left possible

                while(top->left)
                {
                    st1.push(top->left);
                    top=top->left;
                }
            }

        }

        }

        return false;
    }
*/
int main()
{

    return 0;
}