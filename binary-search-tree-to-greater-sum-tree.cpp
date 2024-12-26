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
void solve(TreeNode* root,vector<int>&s)
{
    if(!root) return ;

    s.push_back(root->val);
    solve(root->left,s);
    solve(root->right,s);
}
void solve1(TreeNode* root,map<int,int>&mp)
{
    if(!root) return ;

    root->val = mp[root->val];
    solve1(root->left,mp);
    solve1(root->right,mp);
}
    TreeNode* bstToGst(TreeNode* root) {
    vector<int>s;
    solve(root,s);
    sort(s.begin(),s.end());
    int n = s.size();
    map<int,int>mp;
    mp[s[n-1]] = s[n-1];
    int sum = s[n-1];
    for(int i=n-2;i>=0;i--)
    {
        mp[s[i]] = s[i] + sum;
        sum += s[i];
    }
    // for(auto it:mp)
    // {
    //     cout<<it.first<<" "<<it.second<<endl;
    // }
    solve1(root,mp);
    return root;

    }
};