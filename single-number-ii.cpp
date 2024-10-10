class Solution {
public:
    int singleNumber(vector<int>& nums) {
    int n = nums.size();
    int ans= 0;
    for(int bit=0;bit<32;bit++)
    {
        int cnt= 0;
        for(int i=0;i<n;i++)
        {
            if(nums[i] &(1<<bit)) cnt++;
        }

        cnt %=3;
        if(cnt==1) ans = ans | (1<<bit);
    }
    return ans;
    }
};