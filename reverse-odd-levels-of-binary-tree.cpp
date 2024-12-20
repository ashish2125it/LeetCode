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
    TreeNode* reverseOddLevels(TreeNode* root) {
    if(!root) return root;
    queue< TreeNode* >q;
    q.push(root);
    vector<int>values;
    int level =0;
    while(!q.empty())
    {
        int size = q.size();
        vector<int>temp;
        for(int i=0;i<size;i++)
        {
            TreeNode* front = q.front();
            if(level%2)
            front->val = values[size-i-1];
            q.pop();
            if(front->left)
            {
            q.push(front->left);
            temp.push_back(front->left->val);
            }
            if(front->right)
            {
            q.push(front->right);
            temp.push_back(front->right->val);
            }
        }
        level++;
        values = temp;

    }
    return root;
    }
};