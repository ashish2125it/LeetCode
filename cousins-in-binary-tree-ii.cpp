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
    TreeNode* replaceValueInTree(TreeNode* root) {
    if(!root) return root;
    queue<TreeNode*>q;
    q.push(root);
    vector<int>lvl_sum;
    while(q.size()>0)
    {
        int size = q.size();
        int sum =0;
        for(int i=0;i<size;i++)
        {
            TreeNode* node = q.front();
            q.pop();
            sum += node->val;

            if(node->left)
            q.push(node->left);

            if(node->right)
            q.push(node->right);
        }
        lvl_sum.push_back(sum);
    }
    
    root->val = 0;
    q.push(root);
   
    int lvl =0 ;
    while(q.size())
    {
         int size = q.size();
         for(int i=0;i<size;i++)
         {
            int sum =0;
            TreeNode* node = q.front();
            q.pop();

            if(node->left)
            {
                sum += node->left->val;
                q.push(node->left);
            }

            if(node->right) 
            {
            sum += node->right->val ;    
            q.push(node->right);
            }

            if(node->left)
            {
              node->left->val = lvl_sum[lvl+1] - sum ;
            }

            if(node->right)
            {
             node->right->val = lvl_sum[lvl+1] - sum ;
            }

         }
         lvl++;
    }

    return root;

    }
};