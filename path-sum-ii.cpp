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
void solve(TreeNode* root, int targetSum,vector<int>&temp,vector<vector<int>>&ans)
{
     if(!root) return ;
    if(root->left==NULL && root->right==NULL) {
         if(targetSum-root->val==0)
         {
            temp.push_back(root->val);
            ans.push_back(temp);
            temp.pop_back();
         }
         return ;
    }
   
    
    temp.push_back(root->val);
     solve(root->left,targetSum-root->val,temp,ans);
   
    solve(root->right,targetSum-root->val,temp,ans);
     temp.pop_back();

}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>>ans;
    if(!root) return ans;

    vector<int>temp;
    solve(root,targetSum,temp,ans);
    return ans;

    }
};