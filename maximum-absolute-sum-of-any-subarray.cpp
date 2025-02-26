class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
       // apply the Kadne's algo to find the maxsum
       int sum =0,maxsum = INT_MIN;
       for(int i=0;i<n;i++)
       {
           sum += nums[i] ;
           maxsum = max(maxsum,sum);
           if(sum<0)
           sum =0;
       }
        // apply the Kadne's algo to find the minsum
        sum =0;
        int minsum = INT_MAX;
        for(int i=0;i<n;i++)
        {
            sum += nums[i];
            minsum = min(minsum,sum);
            if(sum >0) 
            sum =0;
        }
        minsum = abs(minsum);
        return max(minsum,maxsum );
    }
};