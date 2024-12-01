class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
    int n = nums.size();
    int sum =0;
    unordered_map<int,int>index,mp;
    for(int i=0;i<n;i++)
    {
        index[nums[i]] = i;
        mp[nums[i]]++;
        sum += nums[i];
    }
    
    int ans= INT_MIN ;
    for(int i=0;i<n;i++)
    {
        int t = sum - nums[i];
        if(t%2==0)
        {
            t = t/2;
            if(mp.find(t)!=mp.end())
            {
                if(mp[t]>=2)
                {
                    ans = max(ans,nums[i]);
                }
                else if(mp[t]==1 && index[t]!=i)
                {
                     ans = max(ans,nums[i]);
                }
            }
        }
    }
    return ans;
    }
};