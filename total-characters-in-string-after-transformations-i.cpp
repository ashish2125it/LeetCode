class Solution {

public:

void solve(int t,vector<vector<int>>&dp)
{
    int mod = 1e9 + 7;
    
    for(int i=0;i<=t;i++)
    {
        for(int j=0;j<26;j++)
        {
            if(i==0)
            {
                dp[j][i] = 1;
            }
            else
            {
                 if(j==25)
                 {
                    dp[j][i] = (dp[0][i-1]%mod + dp[1][i-1]%mod)%mod;
                    dp[j][i] = dp[j][i]%mod;
                 }
                 else
                 dp[j][i] = dp[j+1][i-1]%mod;
            }
        }
    }
}



    int lengthAfterTransformations(string s, int t) {
    vector<vector<int>>dp(26,vector<int>(t+1,-1));
    solve(t,dp);
    int mod = 1e9+7;
    int ans =0;
    for(int i=0;i<s.length();i++)
    {
        int temp = dp[s[i]-'a'][t];
        temp = temp%mod;
        ans = (ans%mod + temp%mod)%mod;
    }

    return ans;
    }
};