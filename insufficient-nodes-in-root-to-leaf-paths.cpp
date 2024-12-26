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
bool solve(TreeNode* root, int limit,int sum,bool left,bool right)
{
     if(!root) {
        return sum<limit;
     }

     left = solve(root->left,limit,sum+root->val,left,right);
     right= solve(root->right,limit,sum+root->val,left,right);

     if(!root->left && !root->right)
     return left && right ;

     if(root->left!=NULL && root->right!=NULL)
     {
        if(left)
      {  root->left =  NULL;
         
      }

        if(right)
        {
        root->right = NULL;
        }

        return left && right;

     }

     if(root->left)
     {
        if(left) 
      {  root->left = NULL;
        
      }
      return left ;

     }

     if(root->right)
     {
         if(right)
      {
        root->right = NULL;
        
      } 
      return right;

     }

      return left && right;
     }



    TreeNode* sufficientSubset(TreeNode* root, int limit) 
    {
        if(solve(root,limit,0,false,false)) return NULL;
        return root;
    }
};