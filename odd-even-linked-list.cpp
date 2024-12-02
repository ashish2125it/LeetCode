class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* odd = head;            // First odd node
        ListNode* even = head->next;     // First even node
        ListNode* evenHead = even;       // Keep track of the even list head

        while (even && even->next) {     // Ensure valid even pointer and its next node
            odd->next = even->next;      // Link the next odd node
            odd = odd->next;             // Move odd pointer
            even->next = odd->next;      // Link the next even node
            even = even->next;           // Move even pointer
        }

        odd->next = evenHead;            // Attach even list at the end of odd list
        return head;
    }
};
