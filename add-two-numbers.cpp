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
ListNode* reverse(ListNode* head)
{
    ListNode* curr = head;
    ListNode* prev = NULL;
    ListNode* next ;

    while(curr)
    {
        next = curr->next;
        curr->next =  prev;
        prev = curr;
        curr = next;
    }

    return prev; 
}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if(!l1) return l2;
    if(!l2) return l1;
    if(!l1 && !l2) return NULL;
    ListNode* curr1 = l1;
    ListNode* curr2 = l2;

    int carry= 0; 
    ListNode* dummy = new ListNode(0);
    ListNode* ans = dummy;
    while(curr1 && curr2)
    {
       int sum = curr1->val + curr2->val + carry;
       int digit = sum%10;
       carry = sum/10;
       ListNode* temp = new ListNode(digit);

       ans->next = temp;
       ans= ans->next;

       curr1 = curr1->next;
       curr2 = curr2->next;
    }


     while(curr1)
    {
       int sum = curr1->val + carry;
       int digit = sum%10;
       carry = sum/10;
       ListNode* temp = new ListNode(digit);

       ans->next = temp;
       ans= ans->next;

       curr1 = curr1->next;
    }
   
      while(curr2)
    {
       int sum =  curr2->val + carry;
       int digit = sum%10;
       carry = sum/10;
       ListNode* temp = new ListNode(digit);

       ans->next = temp;
       ans= ans->next;

       curr2 = curr2->next;
    }

    while(carry)
    {
          int sum =  carry;
       int digit = sum%10;
       carry = sum/10;
       ListNode* temp = new ListNode(digit);

       ans->next = temp;
       ans= ans->next;
    }
   
   return dummy->next;
  //  ListNode* Rev = reverse(ans->next);

   // return Rev;

    }
};