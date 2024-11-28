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
    bool solve(TreeNode* root,int mini,int maxi)
    {
        if(!root) return 1;

        if(root->val<maxi && root->val>mini)
        {
            bool left = solve(root->left,mini,root->val);
            bool right = solve(root->right,root->val,maxi);
            return left && right;
        }
        else
        return 0;
    }
    bool isValidBST(TreeNode* root) {
    return solve(root,INT_MIN,INT_MAX);        
    }
};