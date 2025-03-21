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
    vector<int> inorderTraversal(TreeNode* root) {
     vector<int>inorder;
     if(!root) return inorder;
     TreeNode* curr = root ;

     while(curr)
     {
          if(curr->left==NULL) // print the curr node and go to right
          {
              inorder.push_back(curr->val);
              curr = curr->right;
          }
          else
          {
             //  find out the rightmost node
             TreeNode* prev = curr->left;
             while(prev && prev->right && prev->right!=curr)
             {
                prev = prev->right;
             }

             if(prev->right==NULL )  // make a connection it is the first time 
            { prev->right = curr;
              curr = curr->left;
            }
             else // it is already a connection it means left subtree already visited
             {
                 prev->right = NULL ;
                 inorder.push_back(curr->val);
                 curr = curr->right;
             }

          }
     }
     return inorder;

    }
};