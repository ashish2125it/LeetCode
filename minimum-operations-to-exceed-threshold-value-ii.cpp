#define ll long long int
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
    int n = nums.size();
    priority_queue<ll>q;
    for(auto it:nums)
    q.push(-1*it);
    
    int cnt= 0;
    while(q.size()>=2)
    {
        
        ll mini1 = -1*q.top();
        if(mini1>=k) 
        return cnt;
        q.pop();
        ll mini2 = -1*q.top();
        q.pop();
        ll p = 1LL*2*min(mini1,mini2) + max(mini1,mini2);
        q.push(-1*p);
        cnt++;

    }
    return cnt;
    

    }
};