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
void solve(TreeNode* root)
{
    if(!root) return ;

    temp.push_back(root->val);

    solve(root->left);
    solve(root->right);

}


void solve1(TreeNode* root,vector<pair<int,int>>&sum,int n)
{
    if(!root) return ;


    // find the 
    int low = 0,high = n-1;
    while(low<=high)
    {
        int mid = (low + high)/2;

        if(sum[mid].first==root->val)
        {
            root->val = sum[mid].second;
            break;
        }
        else if(sum[mid].first > root->val)
        {
           high = mid-1;
        } 
        else
          low = mid + 1;
    }

    solve1(root->left,sum,n);

    solve1(root->right,sum,n);

}
    TreeNode* convertBST(TreeNode* root) {
    if(!root) return root;
    solve(root);
    sort(temp.begin(),temp.end());
    int n = temp.size();
    vector<pair<int,int>>sum(n);

    sum[n-1].first = temp[n-1];
    sum[n-1].second = temp[n-1];

    for(int i=n-2;i>=0;i--)
    {
        sum[i].first = temp[i];
        sum[i].second = sum[i+1].second + temp[i];
    }

    solve1(root,sum,n);

    return root;


    }
};