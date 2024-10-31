#define ll long long

class Solution {
ll solve(int i,int j,vector<int>& r,vector<int>& fa,vector<vector<ll>>&dp)
{
    if(i>=r.size()) return 0;
    if(j>=fa.size()) return 1e18;
    if(dp[i][j]!=-1) return dp[i][j];

    ll repair = abs(r[i]-fa[j]) + solve(i+1,j+1,r,fa,dp);
    ll skip = solve(i,j+1,r,fa,dp);
    return dp[i][j] = min(repair,skip);
}
public:
    long long minimumTotalDistance(vector<int>& r, vector<vector<int>>& f) {
    sort(r.begin(),r.end());
    sort(f.begin(),f.end());
    vector<int>fa;
    for(int i=0;i<f.size();i++)
    {
        int limit = f[i][1];
        for(int j=0;j<limit;j++) fa.push_back(f[i][0]);
    }
    vector<vector<ll>>dp(r.size()+1,vector<ll>(fa.size()+1,-1));
    int n = r.size(),m = fa.size();
 
    return solve(0,0,r,fa,dp);


    }
};