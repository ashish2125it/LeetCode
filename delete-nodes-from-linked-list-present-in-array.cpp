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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
    set<int>s;
    for(auto it:nums) s.insert(it);
    ListNode* d = new ListNode(-1);
    ListNode* prev = d;
    d->next = head;
    ListNode* curr = head;
    while(curr)
    {
        if(s.find(curr->val)!=s.end())
        {
            ListNode* next = curr->next;
            prev->next = next;
            curr  = next;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
    return d->next;
    }
};