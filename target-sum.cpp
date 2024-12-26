class Solution {
public:
int solve(int index,int target,vector<int>&arr,vector<vector<int>>&dp)
{
    if(index==0)
    {
        if(target==0 && arr[0]==0) return 2;
        if(target==0 || target==arr[0]) return 1;
        return 0 ;
    }
    if(target <0) return 0;
    if(dp[index][target] != -1) return dp[index][target]; 
    int nottake = solve(index-1,target,arr,dp);
    int take =0;
    if(target >= arr[index])
    take = solve(index-1,target-arr[index],arr,dp);

    return dp[index][target] = take + nottake ;
}
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        int totSum =0;
        int n =nums.size();
        for(int i=0;i<n;i++)
        totSum += nums[i];

        int tar = (totSum + target )/2 ;
        if(totSum + target <0 || (totSum + target ) %2==1) return 0;
        vector<vector<int>>dp(n,vector<int>(tar+1,-1));
        return solve(n-1,tar,nums,dp);
    }
};