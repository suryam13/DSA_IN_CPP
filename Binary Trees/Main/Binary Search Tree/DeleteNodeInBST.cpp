#include<bits/stdc++.h>
using namespace std;

//LC 450 

/*
My Method : 
A bit complex and could be considered as brute as i
am reonstructing the entire part of tree below the target node
    TreeNode* parent=NULL;
    TreeNode* helper(TreeNode* root, int key) {
        if (!root)
            return NULL;

        if (root->val == key)
            return root;

        if (root->val > key)
        {
            // left
            if(root->left && root->left->val==key) parent=root; 
            return helper(root->left, key);
        } 

        else 
        {
            // right
            if(root->right && root->right->val==key) parent=root; 
            return helper(root->right, key);
        } 
            
    }

    void inorder(TreeNode* root,vector<int>& v,int val)
    {
        if(!root)
        return;

        inorder(root->left,v,val);
        if(root->val!=val) v.push_back(root->val);
        inorder(root->right,v,val);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {

        if(!root)
        return NULL;

        // finding whether the key value is present or not and if yes then at which position
      
        TreeNode* posi = helper(root, key);

        if(!posi) //not found so no deletion
        return root;

        // performing an in order traversal to find out what are the elements
        // linked to this posi and it would be automatically in sorted order

        
        vector<int> v;
        inorder(posi,v,posi->val); //sending posi->val to avoid adding the value which is to be deleted

        if(parent==NULL) parent=root;

        if(v.empty())
        {  
            if(key==parent->val)
            return NULL;

            if(key>parent->val) parent->right=NULL;
            else parent->left=NULL;
            return root;
        }

        posi->val=v[0]; //changing the deleted value root with new value in vec so as to not break the
        //earlier connections with the to be deleted root
        posi->right=NULL; //making it fresh
        posi->left=NULL; //making it fresh

        TreeNode* prev=posi;

        for(int i=1;i<v.size();i++) //starting from 1 as the 0th position is been alloted
        {
            TreeNode* ele=new TreeNode(v[i]);
            prev->right=ele; //all the values would be surely on right as inorder is stored in sorted 
            //manner so larger value at right
            prev=ele;
        }

        return root;
    }
*/

/*
Another Approach : 


    /*
        The motive is to attach the left part of the toBeDeleted node to the  
        parent of toBeDeleted node and track the rightmost part of the one which is now attached to the
        parent and over there attach the right part of the toBeDeleted node

        have an addtional check whether the toBeDeleted node lies to left or right 
    */

    /*

    TreeNode* parent=NULL;
    TreeNode* find(TreeNode* root, int key) {
       if (!root)
           return NULL;

       if (root->val == key)
           return root;

       if (root->val > key)
       {
           // left
           if(root->left && root->left->val==key) parent=root; 
           return find(root->left, key);
       } 

       else 
       {
           // right
           if(root->right && root->right->val==key) parent=root; 
           return find(root->right, key);
       } 
           
   }

   TreeNode* right(TreeNode* root) //returns the rightmost node in the left half of the toBeDeleted one
   {
       if(!root)
       return NULL;

       if(root->right!=NULL)
       return right(root->right);

       else 
       return root;
   }


   TreeNode* deleteNode(TreeNode* root, int key) {

       if(!root)
       return NULL;

       //finding whether the key is there or not and also the parent of the toBeDeleted in order to
       //attach the respective nodes

       TreeNode* posi=find(root,key); //gives the position of the target

       if(!posi) //means key not found
       return root; //no deletions

      
       if(posi==root) //means the root is to be deleted
       {
           if(posi->left) //means make this the root
           {   
               TreeNode* rightt=NULL;
               if(root->right) rightt=root->right;

               if(root->right)
              { 
               root=posi->left;
               TreeNode* rightmost= right(posi->left);
               rightmost->right=rightt;
               }

               
               return posi->left;
           }

           else if(posi->right) //means make the right part the root
           {
               return posi->right;
           }

           else 
           return NULL;
       }

       if(key>parent->val) // means on the right side
       {
            if(posi->left) //exist
           {
               parent->right=posi->left;

           //now find the rightmost node in posi->left;

           TreeNode* rightmost= right(posi->left);
           rightmost->right=posi->right;}

            else if(posi->right) //means right exists
           {
               parent->right=posi->right; 
               //since there is no left child so directly attach the right
               //part
           }

            else
           {
               //means it is the leaf to be deleted
               parent->right=NULL;
           }

       }


       else //lies on the left side
       {
           if(posi->left) //exist
           {parent->left=posi->left;

           //now find the rightmost node in posi->left;

           TreeNode* rightmost= right(posi->left);
           rightmost->right=posi->right;}

           else if(posi->right) //means right exists
           {
               parent->left=posi->right; 
               //since there is no left child so directly attach the right
               //part
           }

           else
           {
               //means it is the leaf to be deleted
               parent->left=NULL;
           }

       }

       return root;
   }
    */

 int main()
{
    
    return 0;
}