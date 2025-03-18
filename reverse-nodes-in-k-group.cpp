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
int find(ListNode* head)
{
    int len =0;
    ListNode* temp = head;
    while(temp)
    {
        len++;
        temp = temp->next;
    }

    return len;
}

ListNode* solve(ListNode* head,int len,int k)
{
    if(len<k) return head;

    // now reverse the k nodes
    ListNode* curr = head;
    ListNode* prev = NULL;
    ListNode* next = NULL;
    int cnt= 0;
    while(curr && cnt<k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        cnt++;
    }

    if(next!=NULL)
    {
        head->next = solve(next,len-k,k);
    }

    return prev;


}
    ListNode* reverseKGroup(ListNode* head, int k) {
    if(!head) return head;

    int len = find(head);   
    return solve(head,len,k);

    }
};