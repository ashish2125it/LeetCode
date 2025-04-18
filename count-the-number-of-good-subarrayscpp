#define ll long long
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
    ll ans= 0,n = nums.size(),cnt=0;
    int i=0,j=0;
    unordered_map<int,int>mp;
    while(j<n)
    {
       cnt += mp[nums[j]];
       mp[nums[j]]++;
       while(cnt>=k && j>=i)
       {
          ans += (n-j);
          mp[nums[i]]--;
          cnt -= mp[nums[i]];
          if(mp[nums[i]]==0) mp.erase(nums[i]);
          i++;
       }
       j++;
    }

    return ans;

    }
};