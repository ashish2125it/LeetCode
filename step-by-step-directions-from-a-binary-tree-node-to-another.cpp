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
string start_to_LCA = "";
string LCA_to_end = "";
bool start_to_Node(TreeNode* lca,int start)
{
    if(!lca) return 0;
    if(lca->val==start) return 1;

    if(lca->left && start_to_Node(lca->left,start)==1) 
    {
        start_to_LCA += "U";
        return 1;
    }

    if(lca->right && start_to_Node(lca->right,start)==1)
    {
        start_to_LCA += "U";
        return 1;
    }

    return 0;
}

bool LCA_to_End(TreeNode* lca,int end)
{
    if(!lca) return 0;
    if(lca->val==end) return 1;


    if(LCA_to_End(lca->left,end))
    {
        LCA_to_end += "L";
        return 1;
    }

     if(LCA_to_End(lca->right,end))
    {
        LCA_to_end += "R";
        return 1;
    }

    return 0;
    
}
TreeNode* solve(TreeNode* root,int p,int q)
{
    if(!root) return NULL;
    if(root->val==p || root->val==q) return root;

    TreeNode* left = solve(root->left,p,q);
    TreeNode* right = solve(root->right,p,q);

    if(left && right) return root;
    if(!left && right) return right;
    if(left && !right) return left;
    return NULL;
}


    string getDirections(TreeNode* root, int startValue, int destValue) {
    string ans = "";
    TreeNode* LCA = solve(root,startValue,destValue);

    // now find a path from start to LCA  -> "UUUU...."
    // then find the path from LCA to end Node

    start_to_Node(LCA,startValue);

    LCA_to_End(LCA,destValue);
    
    reverse(LCA_to_end.begin(),LCA_to_end.end());
    return start_to_LCA + LCA_to_end  ;




    


      


    }
};