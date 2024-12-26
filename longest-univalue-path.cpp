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
int ans= 0;
int solve(TreeNode* root)
{
    if(!root) return 0;

    int left_path = solve(root->left);
    int right_path = solve(root->right);

    int left= 0,right = 0;

    if(root->left && root->val==root->left->val)
    {
        left = 1 + left_path ;
    }

    if(root->right && root->right->val==root->val)
    {
        right = 1 + right_path;
    }

    ans = max(ans,left+right);
    return max(left,right);

}
    int longestUnivaluePath(TreeNode* root) {
        solve(root);
        return ans;
    }
};