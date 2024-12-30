
class Solution {
public:
int solve(int len, int zero, int one,vector<int>&dp)
{
   if(len==0) return 1;
   if(len<0) return 0;
   if(dp[len]!=-1) return dp[len];
    int mod = (1e9+7);

    int Take_Zero = solve(len-zero,zero,one,dp);
    int Take_One = solve(len-one,zero,one,dp);
    return dp[len] = (Take_Zero%mod + Take_One%mod)%mod;


}
    int countGoodStrings(int low, int high, int zero, int one) {
       int ans= 0;
        int mod = (1e9+7);
         vector<int>dp(high+1,-1);
       for(int i=low;i<=high;i++)
       {
          ans =( ans + solve(i,zero,one,dp))%mod;
       }
       ans %= mod;
       return ans;
    }
};