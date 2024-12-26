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
    ListNode* removeNodes(ListNode* head) {
    if(!head) return head;
    int len =0 ;
    ListNode* curr = head;
    vector<int>temp;
    while(curr)
    {
        len++;
        temp.push_back(curr->val);
        curr = curr->next;
    }

    vector<int>g(len,-1);
    stack<int>s;
    for(int i=len-1;i>=0;i--)
    {
        while(!s.empty() && temp[i]>=temp[s.top()])
        {
            s.pop();
        }
        if(!s.empty())
        g[i] = s.top();
        s.push(i);
    }

    int cnt= 0;
    curr = head;
    ListNode* d =new ListNode(-1);
    ListNode* prev = d;
    d->next = head;
    while(curr)
    {
        if(g[cnt]!=-1)
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
           cnt++;
    }

    return d->next;


    }
};