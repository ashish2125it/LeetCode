/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
TreeNode* prev = NULL;
TreeNode* first = NULL ;
TreeNode* middle = NULL ;
TreeNode* last = NULL;

 void inorder(TreeNode* root)
 {
    if(!root) return;

     inorder(root->left);
     
     if(prev!=NULL && prev->val > root->val)
     {
         
         // check first voilation 
         if(first==NULL)
         {
            first = prev;
            middle = root;
         }
         else // 2nd voilation
         {
             last = root;
         }

     }
     prev = root;


     inorder(root->right);
 }
    void recoverTree(TreeNode* root) {
     if(!root) return ;

     inorder(root);
     if(first && last)
     {
        swap(first->val,last->val);
     }
     else
     swap(first->val,middle->val);


    

    }
};