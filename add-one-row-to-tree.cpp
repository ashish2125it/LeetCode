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

void solve(TreeNode* root,int curr_depth,int depth,int val)
{
    if(!root) return ;



    if(curr_depth==depth-1)
    {
         TreeNode* left_tree = root->left;
         TreeNode* right_tree = root->right;

         TreeNode* left_child = new TreeNode(val);
         TreeNode* right_child =  new TreeNode(val);

         root->left = left_child;
         left_child->left = left_tree;

         root->right = right_child;
         right_child->right = right_tree;
    }
    else
    {
        solve(root->left,curr_depth+1,depth,val);
        solve(root->right,curr_depth+1,depth,val);
    }
}
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
    if(!root) return NULL;
    if(depth==1)
    {
        TreeNode* prev_root = root;
        TreeNode* curr_root = new TreeNode(val);
        curr_root->left = prev_root; 
        return curr_root;
    }

    solve(root,1,depth,val);
    return root;

        
    }
};