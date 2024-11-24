class Solution {
public:
int solve(int i,int n,vector<int>&nums,int k,int op1,int op2,vector<vector<vector<int>>>&dp)
{
    if(i>=n) return 0;
    if(dp[i][op1][op2]!=INT_MIN) return dp[i][op1][op2];

    
    int s1 = 1e9,s2 = 1e9,s3 = 1e9,s4 =1e9,s5 = 1e9;
    if(op1>0)
    {
        if(nums[i]%2==0)
        s1 = (nums[i]/2) + solve(i+1,n,nums,k,op1-1,op2,dp);
        else
        s1 = (nums[i]/2) +1 + solve(i+1,n,nums,k,op1-1,op2,dp);
    }

    if(op2>0)
    {
        if(nums[i]>=k)
        {
            s2 = (nums[i]-k) + solve(i+1,n,nums,k,op1,op2-1,dp);
        }
    }

    int temp = nums[i];
    if(op1>0 && op2>0)
    {
    if(nums[i]%2==0)
    {
         temp = nums[i]/2;
    }
    else
    temp = (nums[i]/2 ) + 1 ;

    if(temp>=k)
    s3 =  (temp-k) + solve(i+1,n,nums,k,op1-1,op2-1,dp);
    }
    s4 = nums[i] + solve(i+1,n,nums,k,op1,op2,dp);


    if(op1>0 && op2>0)
    {
        if(nums[i]-k>=0)
        {
            s5 = (nums[i]-k+1)/2 + solve(i+1,n,nums,k,op1-1,op2-1,dp);
        }
    }

    int m =  min(min(s1,s2),min(s3,s4))   ;
    m = min(m,s5);
    return dp[i][op1][op2] = m; ;
    

}
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
    int n = nums.size();
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(op1+1,vector<int>(op2+1,INT_MIN))) ;
    return solve(0,n,nums,k,op1,op2,dp);
    }
};