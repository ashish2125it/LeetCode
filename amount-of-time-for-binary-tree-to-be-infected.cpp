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
void solve(TreeNode* root,map<TreeNode*,TreeNode*>&mp)
{
     if(!root) 
     return ;
     

     if(root->left)
     {
     mp[root->left] =  root;
     solve(root->left,mp);
     }


     if(root->right)
     {
        mp[root->right] = root;
        solve(root->right,mp);
     }
   
}

TreeNode* f(TreeNode* root,int node)
{
    if(!root) return NULL;
    if(root->val==node) return root;

    TreeNode* left = f(root->left,node);
    TreeNode* right = f(root->right,node);

    if(left) return left;
    return right; 

}
    int amountOfTime(TreeNode* root, int start) {
    if(!root) return 0;
    map<TreeNode*,TreeNode*>mp;
    mp[root] = NULL;
    solve(root,mp);

    queue<TreeNode*> q;
    TreeNode*  temp = f(root,start);
    q.push(temp);
    map<TreeNode*,int>vis;
    vis[temp] = 1;

    int time= 0;
    while(q.size())
    {
        int size = q.size();
        int a= 0; 
        for(int i=0;i<size;i++)
        {
            TreeNode* front = q.front();
            q.pop();

            if(front->left && vis[front->left]==0)
            {
                q.push(front->left);
                vis[front->left] = 1;
                a = 1;
            }

             if(front->right && vis[front->right]==0)
            {
                q.push(front->right);
                vis[front->right] = 1;
                a = 1;
            }

             if(mp[front] && vis[mp[front]]==0)
            {
                q.push(mp[front]);
                vis[mp[front]] = 1;
                a = 1;
            }

        }
        if(a)
        time++;
    } 

    return time;


    }
};