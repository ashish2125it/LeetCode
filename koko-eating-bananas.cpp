class Solution {
public:

long long int solve(int speed,vector<int>&nums)
{
    long long int time =0;
    int size = nums.size();
    for(int i=0;i<size;i++)
    {
        if(nums[i]%speed==0)
        time += (nums[i]/speed);
        else
        time = time + 1 +  (nums[i]/speed);
    }

    return time;
}
    int minEatingSpeed(vector<int>& p, int h) {
        int n = p.size();

        int low= 1,high = 0;
        for(auto it:p) high = max(high,it);
        
        int ans= 0;
        while(low<=high)
        {
            int mid = (low+high)/2;

            if(solve(mid,p) <= h)
            {
                ans = mid;
                high = mid-1;
                
            }
            else
            {
                low = mid+1;

            }
        } 

        return ans;

    }
};