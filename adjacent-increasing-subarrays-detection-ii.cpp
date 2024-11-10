class Solution {
public:
bool check(int len,vector<int>l)
{
    for(int i=0;i<l.size();i++)
    {
        if(l[i]>=len && i-len>=0 && l[i-len]>=len) return 1;
     }
     return 0;
}
    int maxIncreasingSubarrays(vector<int>& nums) {
    int n = nums.size();
    vector<int>len(n,1);
    for(int i=1;i<n;i++) 
    {
        if(nums[i]>nums[i-1]) len[i] = 1 + len[i-1];
    }

    int l = 1,h = n;
    int ans = 0;
    while(l<=h)
    {
        int mid = (l+h)/2;
        if(check(mid,len))
        {
            ans = mid;
            l = mid+1;
        }
        else
        h = mid-1;

    }

    return ans;
    }
};