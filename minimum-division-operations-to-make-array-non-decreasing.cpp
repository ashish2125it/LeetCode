class Solution {
public:
int solve(int n)
{
    int maxi = -1;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            int second = n/i;
            int b = max(second,i);
            maxi = max(maxi,b);
        
        }
    }

    return maxi ;
}
    int minOperations(vector<int>& nums) {
    int n = nums.size();
    int cnt= 0;
    for(int i=n-2;i>=0;i--)
    {
        while(nums[i]>nums[i+1])
        {
            int d1 = solve(nums[i]);
            if(d1!=-1)
            {
                nums[i] /= d1;
            }
            else
            return -1;

            cnt++;
        }
    }

    return cnt;
    }
};