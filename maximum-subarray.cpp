class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    int sum =0 ,ans= INT_MIN;
    for(int i=0;i<n;i++)
    {
        sum +=  nums[i];
       
        ans =max(ans,sum);
        if(sum<0)
        sum =0;
    }
    return ans;
    }
};