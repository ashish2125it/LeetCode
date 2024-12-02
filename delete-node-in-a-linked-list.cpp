/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
    if(!node) return ;
    ListNode* next = node->next;
    int val1 = node->val;
    int val2 = next->val;
    node->val = val2;
    next->val = val1;
    node->next = next->next;
    delete(next);
    return ;
    }
};