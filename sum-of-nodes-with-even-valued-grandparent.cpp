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
void f(TreeNode* root,map<TreeNode*,TreeNode*>&mp)
{
    
    if(root->left)
    {
        mp[root->left] = root;
        f(root->left,mp);
    }

    if(root->right)
    {
        mp[root->right] = root;
        f(root->right,mp);
    }
}

void solve(TreeNode* root,int &ans,map<TreeNode*,TreeNode*>&mp)
{
    if(!root) return ;

    TreeNode* parent = mp[root];
    if(parent)
    {
        TreeNode* grand_parent = mp[parent];
        if(grand_parent && grand_parent->val%2==0)
        ans += root->val;
    }

    solve(root->left,ans,mp);
    solve(root->right,ans,mp);
}
    int sumEvenGrandparent(TreeNode* root) {
    map<TreeNode*,TreeNode*>mp;
    if(!root) return 0;
    int ans=0;
    mp[root] = NULL;
    // {child} -> {parent}
    f(root,mp);
    solve(root,ans,mp);   
    return ans; 
    }
};