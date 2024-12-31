class Solution {
public:
int solve(int index,int n,vector<int>& days,vector<int>& costs,vector<int>&dp)
{ 
    if(index >= n) return 0;
    if(dp[index] != -1e9) return dp[index];

   // 1day pass
    int opt1 = costs[0] + solve(index+1,n,days,costs,dp);
    int i;
    for(i =index;i<n && days[i] < days[index] + 7 ;i++ );

    int opt2 = costs[1] + solve(i,n,days,costs,dp);

    for(i=index;i<n && days[i] < days[index] + 30 ;i++);

    int opt3 = costs[2] + solve(i,n,days,costs,dp);

    return  dp[index] = min(opt1,min(opt3,opt2));
}
    int mincostTickets(vector<int>& days, vector<int>& costs) 
    {
        int n =days.size();
        vector<int>dp(n,-1e9);
        return solve(0,n,days,costs,dp);
    }
};