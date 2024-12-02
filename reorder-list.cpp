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
ListNode* reverse_node(ListNode*head)
{
    ListNode* curr = head;
    ListNode* prev = NULL;
    ListNode* next;

    while(curr)
    {
        next = curr->next;
        curr->next=  prev;
        prev = curr;
        curr = next;
    }
    return prev;

}
    void reorderList(ListNode* head) {
    if(!head || !head->next || !head->next->next) return ;

    ListNode* slow = head;
    ListNode* fast = head;
    while(slow && fast->next && fast->next->next)
    {
        slow = slow ->next;
        fast = fast->next->next;
    }

      ListNode* Next = slow->next;
      slow->next= NULL;
      ListNode* rev = reverse_node(Next);
      ListNode* p1 = head;
      ListNode* ans = p1;
      ListNode* p2 = rev;
      while(p1 && p2)
      {
        ListNode* save_next1 = p1->next;
        ListNode* save_next2 = p2->next;
        p1->next = p2;
        p2->next = save_next1;
        p1 = save_next1;
        p2 = save_next2;
      }

     

    }
};