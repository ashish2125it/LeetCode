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


    unordered_map<int,int>mp;
    ListNode* temp = head;

    while(temp)
    {
        mp[temp->val]++;
        temp = temp->next; 
    }


    ListNode* curr = head;
    ListNode* dummy = new ListNode(-1);
    ListNode* ans = dummy;
    dummy->next = head;
    ListNode* prev  = dummy; 
    while(curr)
    {
        if(mp[curr->val]>=2) // delete both the nodes
        {
             ListNode* next = curr->next;
             prev->next = next;
             curr = next;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    
    }
    return ans->next;
    }
};