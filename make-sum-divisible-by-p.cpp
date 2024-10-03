#define ll long long
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
    int n = nums.size();
    // we have to find a smallest subarray whose sum rem is x when it is divide by l
    ll tot_sum =0;
    for(auto it:nums) tot_sum += it;
    if(tot_sum%p==0) return 0;
    int rem = tot_sum%p ;
    unordered_map<int,int>mp;
    mp[0] = -1;
    ll sum =0;
    int ans = n;
    for(int i=0;i<n;i++)
    {
      sum += nums[i];
      int curr_rem = sum%p;
      if(mp.find((curr_rem-rem+p)%p)!=mp.end())
      ans = min(ans,i-mp[(curr_rem-rem+p)%p]);
      mp[(curr_rem)] = i ;
    }

    if(ans==n) return -1;
    return ans;



    }
};