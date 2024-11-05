class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,unordered_map<int,int>>dp;
        vector<int>max_for_k(k+1,0);

        for(int i=0;i<n;i++)
        {
            for(int rem=k;rem>=0;rem--)
            {
                dp[nums[i]][rem] = max(dp[nums[i]][rem] + 1, (rem>0 ? max_for_k[rem-1]+1 :0) );
                max_for_k[rem] = max(dp[nums[i]][rem],max_for_k[rem]);
            }
        }
        
        int ans =  0;
        for(int rem=0;rem<=k;rem++)
        {
            ans = max(ans,max_for_k[rem]);
        }
        return ans;

       
      
            
            
          
    }
};