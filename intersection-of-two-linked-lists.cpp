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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(!headA || !headB) return NULL;

    ListNode* curr1 =headA;
    ListNode* curr2 = headB;
    map<ListNode*,int>mp;
    while(curr1)
    {
        mp[curr1]++;
        curr1 = curr1->next;
    }     

     while(curr2)
    {
        mp[curr2]++;
        curr2 = curr2->next;
    }     
    curr1 = headA;
    while(curr1)
    {
        if(mp[curr1]==2) 
        {
            ListNode* ans = curr1;
            return ans;
        }

        curr1 =curr1->next;
    }

    return NULL;

    }
};