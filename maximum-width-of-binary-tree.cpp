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
#define ll long long
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,ll>>q;
        q.push({root,0});
        
        ll ans= 1;
        while(q.size())
        {
            int size = q.size();
            ll first_index = q.front().second;
            ll last_index = q.back().second;
            ans = max(ans,last_index-first_index+1);

            for(int i=0;i<size;i++)
            {
                TreeNode* front = q.front().first;
                ll index = q.front().second-first_index;
                q.pop();

                if(front->left)
                q.push({front->left, 1LL*(2*index+1)}); 

                 if(front->right)
                q.push({front->right, 1LL*(2*index+2)}); 
            }

        }

        return (int)ans;

    }
};