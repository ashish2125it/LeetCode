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
  vector<TreeNode*>ans;
TreeNode* solve(TreeNode* root,unordered_set<int>&s)
{
    if(!root) return NULL;


    root->left = solve(root->left,s);
    root->right = solve(root->right,s);


    if(s.find(root->val)!=s.end())
    {
        if(root->left)
        ans.push_back(root->left);
        if(root->right)
        ans.push_back(root->right);
        return NULL;
    }
    return root;
}
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& d) {
        
         if(!root) return ans;

         unordered_set<int>s;
         for(auto it:d ) s.insert(it);

         solve(root,s);

         if(s.find(root->val)==s.end()) ans.push_back(root);
         return ans;
     }
};