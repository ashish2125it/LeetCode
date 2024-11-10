class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
   
        vector<int>lll(nums.size(),1);
    for(int i=1;i<nums.size();i++)
    {
       if(nums[i]>nums[i-1]) lll[i] = 1 + lll[i-1];
            
    }
        
        for(int i=0;i<nums.size();i++)
        {
            if(lll[i]>=k && i-k>=0 && lll[i-k]>=k) return 1;
        }
        return 0;
   
    }
};