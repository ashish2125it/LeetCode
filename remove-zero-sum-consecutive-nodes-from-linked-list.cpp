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
    ListNode* removeZeroSumSublists(ListNode* head) {
    if(!head) return head;
    unordered_map<int,ListNode*>mp;

    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    mp[0] = dummy ;

    int sum =0;
    ListNode*  curr = head;
    while(curr)
    {
        sum += curr->val ;
      
        if(mp.find(sum)!=mp.end())
        {
            ListNode* temp = mp[sum];
            ListNode* next = curr->next;
            ListNode* d = temp->next;
            int k =  sum;
            while(d!=curr)
            {
                k += d->val;
                mp.erase(k);
                d = d->next;
            }
           

            temp->next = next;
            curr = next;
        }
        else
       { mp[sum] = curr;
         curr = curr->next;
       }

       
    }

    return dummy->next; 

    }
};