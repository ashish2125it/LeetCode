class Solution {
public:
int solve(int prev_indx,int index,vector<int>&nums,int n,vector<vector<int>>&dp)
{
   if(index>=n) return nums[prev_indx];
   if(index==n-1) return max(nums[prev_indx],nums[index]);


    
    if(dp[prev_indx][index]!=-1) return dp[prev_indx][index];

    int opt1 = max(nums[prev_indx],nums[index]) + solve(index+1,index+2,nums,n,dp);
    int opt2 = max(nums[index],nums[index+1]) + solve(prev_indx,index+2,nums,n,dp);
    int opt3 = max(nums[prev_indx],nums[index+1]) + solve(index,index+2,nums,n,dp);

    return dp[prev_indx][index] =  min( min(opt1,opt2),opt3);

     
}
    int minCost(vector<int>& nums) {
    int  n = nums.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    return solve(0,1,nums,n,dp);

    }
};