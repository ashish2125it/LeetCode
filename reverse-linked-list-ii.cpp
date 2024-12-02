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
ListNode* reverse_node(ListNode* head,int times)
{
    ListNode* curr = head;
    ListNode* prev = NULL;
    ListNode* next ;
    while(curr && times)
    {
       next = curr->next; 
       curr->next= prev;
       prev = curr ;
       curr  = next;
       times--;
    }

    return prev;
}
    ListNode* reverseBetween(ListNode* head, int left, int right) {
    if(!head) return head;
    ListNode* dummy = new ListNode(-1) ;
    dummy->next = head;
    ListNode*  prev = dummy;
    ListNode* prev_left = NULL;
    ListNode* curr = head ;
    ListNode* left_node = NULL;
    ListNode* right_node = NULL;
    ListNode* Next = NULL;
    
    int cnt= 0; 
    while(curr)
    {
        cnt++;
        if(cnt==left)
        {
            prev_left = prev;
            left_node = curr;
        }
         if(cnt==right)
        {
            right_node = curr;
            Next = curr->next;
        }

        prev = curr;
        curr = curr->next;
    }
    
  //  cout<<prev_left->val<<" "<<left_node->val<<" "<<right_node->val<<" "<<endl;
    ListNode* rev = reverse_node(left_node,right-left+1);
    cout<<rev->val<<" ";
    prev_left->next = right_node;
    left_node->next = Next;

    return dummy->next;
    }
};