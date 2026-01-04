#include <bits/stdc++.h>
using namespace std;
// LC-106

/*

Method 1 :
     //Codestory with mik method
    TreeNode* helper(vector<int>& postorder,int &idx,vector<int>& inorder,int inStart,int inEnd,unordered_map<int,int> &inMap)
    {
            if(inStart>inEnd)
            return NULL;

            TreeNode* root=new TreeNode(postorder[idx]);
            int inorderIdx=inMap[postorder[idx]];f
            idx=idx-1;


            //note idx is passed by reference so the count in preorder will be maintained
            //so when the entire left inorder is been traversed then the right will come
            //along with its idx updated (i.e the preorder idx) as it is passed by reference

            root->right=helper(postorder,idx,inorder,inorderIdx+1,inEnd,inMap);
            root->left=helper(postorder,idx,inorder,inStart,inorderIdx-1,inMap);

           //the only difference here is we will have to traverse postorder from end as it
           //contains root at last and firstly the rigth part would be called as idx is passed
           // by reference so we would have to deal for 20 root first
            return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        unordered_map<int,int> inMap;
        //stores the inorder values as we want to search the inorder values
        // again and again

        for(int i=0;i<inorder.size();i++)
        {
            inMap[inorder[i]]=i;
        }
        int idx=postorder.size()-1;

        TreeNode* root = helper(postorder,idx,inorder,0,inorder.size()-1,inMap);

        return root;

    }

*/

/*
Method 2
 /*
            In post order we have L R Root means some part of start would be left then right
            then root
            In in order we have L Root R means the element count of left would be of post order
            left and the right would be the count of post order right and we just have to compare
            the root


      TreeNode* helper(vector<int>& postorder,int pStart,int pEnd,vector<int>& inorder,int inStart,int inEnd, unordered_map<int,int> &inMap)
      {
              if(inStart>inEnd) //not checking for preStart>preEnd because if one goes then
              //obviously second one too goes they are concurrent write either one
              return NULL;

              TreeNode* root=new TreeNode(postorder[pEnd]);


              int rootPos=inMap[root->val];
              int leftSize=rootPos-inStart;
              int rightSize=inEnd-rootPos;
              //location of root element in inorder


              //gives me the count of element to left of inorder (rootPos-inStart)-1 -1 for index
              root->left = helper(postorder,pStart,pStart+(leftSize)-1,inorder,inStart,
               rootPos-1,inMap);
              root->right =helper(postorder,pEnd-(rightSize),pEnd-1,inorder,rootPos+1,inEnd,inMap);
              //even this would work
              //root->right =helper(postorder,pStart+leftSize,pEnd-1,inorder,rootPos+1,inEnd,inMap);


                  Concept :
                  As in post order we have left coming then right and then root,so here we would consider the size
                  of the left right from first index and then the next would be the postorder of the right side,in
                  such case we can do directly with out the help of rightSize variable by just using

                  //root->right =helper(postorder,pStart+leftSize,pEnd-1,inorder,rootPos+1,inEnd,inMap);

                  if to be avoided then it could be in both of the formation techniques LC-105 and LC-106 just with
                  some minor tweaks




              return root;
      }

      TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

          unordered_map<int,int> inMap;
          //stores the inorder values as we want to search the inorder values
          // again and again

          for(int i=0;i<inorder.size();i++)
          {
              inMap[inorder[i]]=i;
          }


          TreeNode* root = helper(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,inMap);

          return root;

      }

*/
int main()
{

    return 0;
}