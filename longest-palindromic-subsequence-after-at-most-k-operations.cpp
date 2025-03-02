class Solution {
public:
int solve(int i,int j,string &s,int k,vector<vector<vector<int>>>&dp)
{
    if(i>j) return 0;
    if(i==j)
    {
        if(s[i]==s[j])
         return 1;
        int forward = abs(s[i]-s[j]);
        int backward = 26 - abs(s[i]-s[j]) ;
        if(k>=min(forward,backward))
        return 1;
        return 0;
    }

    if(dp[i][j][k]!=-1) return dp[i][j][k];



    
    int opt1=0,opt2=0,opt3 =0;
    if(s[i]==s[j])
    opt1 = 2 + solve(i+1,j-1,s,k,dp);
    else
    {
        int forward = abs(s[i]-s[j]);
        int backward = 26 - abs(s[i]-s[j]) ;
        if(k>=min(forward,backward))
        opt1 =  2 + solve(i+1,j-1,s,k-min(forward,backward),dp);
        opt2 = solve(i+1,j,s,k,dp);
        opt3 = solve(i,j-1,s,k,dp);

    }

    return  dp[i][j][k] = max(max(opt1,opt2),opt3);
}
    int longestPalindromicSubsequence(string s, int k) {
    int j = s.length()-1;
    int n = s.length();
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(n+1,vector<int>(k+1,-1)));
    return solve(0,j,s,k,dp);
    }
};