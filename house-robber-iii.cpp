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
pair<int,int> solve(TreeNode* root,int &ans)
{
    if(!root) return {0,0};

    pair<int,int>left = solve(root->left,ans);
    pair<int,int>right = solve(root->right,ans);

     ans = max(ans, max(root->val + left.second+ right.second, left.first + right.first));

     pair<int,int> p ;
     p.first = root->val + max(left.second ,right.second);
     p.second = max(left.first,right.first);

     return p;
    
}
    int rob(TreeNode* root) {
    if(!root) return 0;
    int ans= 0 ;
    solve(root,ans);
    return ans;
    }
};