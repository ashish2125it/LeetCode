#define ll long long
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
    int n = nums.size();
    ll ans = 0;
    map<int,ll>mp;
    for(int i=0;i<n;i++)
    {
        int val = i-nums[i];
        ans += (i-mp[val]);
        mp[val]++;
    }
    return ans;

    }
};