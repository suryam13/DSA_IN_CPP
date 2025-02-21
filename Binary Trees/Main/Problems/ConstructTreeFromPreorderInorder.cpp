#include<bits/stdc++.h>
using namespace std;

//LC : 105 
// O(N+N) N for traversal and N for map
/*
Method 1 :
  
    We have to take the binary tree and then find the root and then split it into two parts 
    then pass the different inorder and postorder for each left and right part differently


    consider eg 
    pre - 1 2 4 5 3 6 7
    in - 4 2 5 1 6 3 7
    int his when we got root as 1 then we have to split left half and right half vy measuring the count of element from left to that index in inorder map
    

    //Codestory with mik method
    TreeNode* helper(vector<int>& preorder,int &idx,vector<int>& inorder,int inStart,int inEnd,unordered_map<int,int> &inMap)
    {
            if(inStart>inEnd)
            return NULL;

            TreeNode* root=new TreeNode(preorder[idx]);
            int inorderIdx=inMap[preorder[idx]];
            idx=idx+1;


            //note idx is passed by reference so the count in preorder will be maintained
            //so when the entire left inorder is been traversed then the right will come 
            //along with its idx updated (i.e the preorder idx) as it is passed by reference
            root->left=helper(preorder,idx,inorder,inStart,inorderIdx-1,inMap);

            root->right=helper(preorder,idx,inorder,inorderIdx+1,inEnd,inMap);
            return root;   
    }



    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> inMap;
        //stores the inorder values as we want to search the inorder values
        // again and again

        for(int i=0;i<inorder.size();i++)
        {
            inMap[inorder[i]]=i;
        }
        int idx=0;

        TreeNode* root = helper(preorder,idx,inorder,0,inorder.size()-1,inMap);

        return root;   
    }

*/


/*
Method 2 
class Solution {
public:
    We have to take the binary tree and then find the root and then split it into two parts 
    then pass the different inorder and postorder for each left and right part differently


    consider eg 
    pre - 1 2 4 5 3 6 7
    in - 4 2 5 1 6 3 7
    int his when we got root as 1 then we have to split left half and right half by measuring the count of element from left to that index in inorder map
    

    TreeNode* helper(vector<int>& preorder,int preStart,int preEnd,vector<int>& inorder,int inStart,int inEnd,unordered_map<int,int> &inMap)
    {   
            if(preStart>preEnd || inStart>inEnd)
            return NULL;

            TreeNode *root=new TreeNode(preorder[preStart]);

            int rootPos = inMap[root->val]; //current root idx in inorder as we have to 
            //seggeregate for the next one
            int leftSide=rootPos-inStart;
            int rightSide=inEnd-rootPos;
            //calculating these values with respect to root position 
            //these are the count of the values from the root to the left and right 

            
            //preStart + 1 because i want to go just next to the preorder idx then count the 
            //the required number of elements for left then the next set of elements would be 
            //the of the right side preorder
            root-> left = helper(preorder,preStart+1,preStart+leftSide,inorder,inStart,         rootPos-1,inMap);
            root-> right = helper(preorder,preEnd-rightSide+1,preEnd,inorder,rootPos+1,inEnd,inMap);

            return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> inMap;
        //stores the inorder values as we want to search the inorder values
        // again and again

        for(int i=0;i<inorder.size();i++)
        {
            inMap[inorder[i]]=i;
        }

        TreeNode* root = helper(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inMap);

        return root;
    }
*/
 int main()
{
    
    return 0;
}