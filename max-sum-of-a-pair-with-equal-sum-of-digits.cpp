class Solution {
public:
    int maximumSum(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int,int>mp; // {sum} -> max_val
    int ans = -1;
    for(int i=0;i<n;i++)
    {
        int sum =0;
        int temp = nums[i];
        while(temp)
        {
            sum += (temp%10);
            temp = temp/10;
        }

        if(mp.find(sum)!=mp.end())
      {  
        ans = max(ans,mp[sum]+nums[i]);
        mp[sum] = max(mp[sum],nums[i]);
      }
        else
        mp[sum] = nums[i];
    }

     return ans;
    }
};