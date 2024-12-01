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
    private:
    int findmaxindex(vector<int>nums,int s,int e){
        int ans=s;
        int maxi=INT_MIN;
        for(int i=s;i<=e;i++){
            if(nums[i]>maxi){
                maxi=nums[i];
                ans=i;
            }
        }
        return ans;
        
    }
    TreeNode* solve(vector<int>&nums,int s,int e){
        if(s>e)
            return NULL;
        if(s==e)
            return new TreeNode(nums[s]);
        int k=findmaxindex(nums,s,e);
        TreeNode*root=new TreeNode(nums[k]);
        root->left=solve(nums,s,k-1);
        root->right=solve(nums,k+1,e);
        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return solve(nums,0,nums.size()-1);
    }
};