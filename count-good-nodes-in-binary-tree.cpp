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
void solve(TreeNode* root,int maxi)
{
    if(!root) return ;


    
    maxi = max(maxi,root->val);
    if(maxi==root->val) ans++; 
    solve(root->left,maxi);
    solve(root->right,maxi);

}
    int goodNodes(TreeNode* root) {
     solve(root,-1e9);
     return ans;   
    }
};