class Solution {
public:

bool solve(int bucket_size,vector<int>&nums,int max_op)
{
    int op =0;

    for(int i=0;i<nums.size();i++)
    {
        long long b_size = (int)ceil((double)nums[i]/bucket_size) -1;
        op += b_size  ;
        if(op > max_op) return 0;
    }
    return 1;
}
    int minimumSize(vector<int>& nums, int max_op) {
    int n = nums.size();
    int low= 1;
    int high =0;
    for(auto it:nums) high = max(high,it);
    
    int ans = high;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(solve(mid,nums,max_op))
        {
            ans = mid;
            high = mid-1;
        }
        else
        low = mid+1;
    }

    return ans;


    }
};