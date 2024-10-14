#define ll long long
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
    ll n = nums.size(),ans=0;
    priority_queue<ll>q;
    
    for(int i=0;i<n;i++)
    q.push(nums[i]);

    int cnt=0 ;
    while(cnt<k && q.size()>0)
    {
        ll top = q.top();
        ans += top;
        q.pop();
        int c=0;
        if(top%3==0)
        c = top/3;
        else
        c = (top/3 ) + 1; 
      //  cout<<"c is "<<c<<endl;
        if(c>0)
        q.push(c);
        cnt++;
    }
    return ans;
    }
};