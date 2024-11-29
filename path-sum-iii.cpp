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
    vector<int>temp; 
    int ans= 0;
    void solve(TreeNode* root, int k)
    {
        if(!root) return ;

        temp.push_back(root->val);
        solve(root->left,k);
        solve(root->right,k);

        long long sum =0;
        for(int i=temp.size()-1;i>=0;i--)
        {
            sum += temp[i];
            if(sum==k) ans++;
        }
        temp.pop_back();
    }
    int pathSum(TreeNode* root, int targetSum) {
     solve(root,targetSum);
     return ans;
    }
};