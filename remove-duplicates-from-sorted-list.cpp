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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
    if(!head || !head->next) return head;
    ListNode* dummy = new ListNode(-1);
    dummy->next = head;
    ListNode* prev = dummy;
    ListNode* curr = head;
    while(curr && curr->next)
    {
        if(curr->val==curr->next->val)
        {
            ListNode* next = curr->next;
            prev->next = curr->next;
           
            curr->next = NULL;  
            curr = next;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
    return dummy->next;
    }
};