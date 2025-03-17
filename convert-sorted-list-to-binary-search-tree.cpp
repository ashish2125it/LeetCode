/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
TreeNode* solve(int start,int end,vector<int>&temp)
{
    if(start>end) return NULL;

    int mid=  (start+end)/2;
    TreeNode* Root = new TreeNode(temp[mid]);

    Root->left = solve(start,mid-1,temp);
    Root->right = solve(mid+1,end,temp);

    return Root;
}
    TreeNode* sortedListToBST(ListNode* head) {
    if(!head) return NULL;
    vector<int>temp;
    while(head) 
    {
        temp.push_back(head->val);
        head = head->next;
    }    

    return solve(0,temp.size()-1,temp);
    }
};