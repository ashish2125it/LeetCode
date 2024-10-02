#define ll long long
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
    ll ans= 0,n = nums.size();
    ll i=0,j=0,sum=0;
    unordered_map<int,int>mp;
    while(j<n)
    {
        sum += nums[j];
        mp[nums[j]]++;
        if(j-i+1==k)
        {
            if(mp.size()==k) ans = max(ans,sum);
           
            int element = nums[i];
            sum -= element;
            mp[nums[i]]--;
            if(mp[nums[i]]==0) mp.erase(nums[i]);
            i++;
        }

        j++;
    }
    return ans;
    }
};