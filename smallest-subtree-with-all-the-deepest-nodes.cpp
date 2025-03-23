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

void solve(TreeNode* root,int lvl,int& max_lvl)
{
      if(!root) 
      return ;

     
      max_lvl = max(max_lvl,lvl);
      solve(root->left,lvl+1,max_lvl);
      solve(root->right,lvl+1,max_lvl);

}
TreeNode* ans = NULL;
TreeNode* solve1(TreeNode* root,unordered_map<TreeNode*,int>&mp)
{
    if(!root) return NULL;
    if(mp.find(root)!=mp.end()) 
    {
    ans = root;    
    return root;
    }

    TreeNode* left = solve1(root->left,mp);
    TreeNode* right = solve1(root->right,mp);

    if(left && right)
     {
        ans=  root;
        return root;
     }

     if(left) return left;
     if(right) return right;
     return NULL;
     
}
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
     if(!root) return root;
     if(!root->left && !root->right) 
     {
        return root;
     }

     int max_lvl =0;
     int lvl= 0;  
     solve(root,lvl,max_lvl);
     cout<<"max level is "<<max_lvl;
     unordered_map<TreeNode*,int>mp;
     queue<TreeNode*>q;
     q.push(root);
     
     lvl=0;
     while(q.size())
     {
        int size = q.size();
        for(int i=0;i<size;i++)
        {
            TreeNode* front = q.front();
            q.pop();
            if(lvl==max_lvl)
            {
                mp[front] = 1;
            }

            if(front->left)
            {
              q.push(front->left);
            }

            if(front->right)
            {
                q.push(front->right);
            }
        }
        lvl++;
     }   

    solve1(root,mp);
    return ans;

    }
};