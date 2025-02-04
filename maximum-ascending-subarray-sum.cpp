class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
    int  n= nums.size();
    vector<int>cnt(n);
    cnt[0] =1;
    for(int i=1;i<n;i++)
    {
        if(nums[i]>nums[i-1])
        cnt[i] = cnt[i-1] + 1;
        else
        cnt[i] = 1;
    }

    int ans = 0;
    vector<int>sum(n);
    sum[0] = nums[0];
    for(int i=1;i<n;i++)
    sum[i] = sum[i-1] + nums[i];

    
    for(int i=0;i<n;i++)
    {
        int len = cnt[i];
        if(len==(i+1))
        ans = max(ans,sum[i]);
        else 
        ans = max(ans,sum[i]-sum[i-len]);


    }
    return ans;
    }
};