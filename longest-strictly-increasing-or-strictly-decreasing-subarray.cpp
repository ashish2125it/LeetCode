class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
    int n = nums.size();
    vector<int>inc(n,1),dec(n,1);
    int maxi = 1;
    for(int i=1;i<n;i++)
    {
        if(nums[i]>nums[i-1]) inc[i]= 1 + inc[i-1];
        maxi = max(maxi,inc[i]);
    }

     for(int i=1;i<n;i++)
    {
        if(nums[i]<nums[i-1]) dec[i]= 1 + dec[i-1];
        maxi = max(maxi,dec[i]);
    }
    return maxi;


    }
};