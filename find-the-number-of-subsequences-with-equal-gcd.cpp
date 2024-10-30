class Solution {
    const int mod = 1e9 + 7;
    
public:
    int solve(int i, vector<int> &nums, int first, int second,vector<vector<vector<int>>>&dp){
       

        if(i == nums.size()){
            return (first && second) && (first == second);
        }
        
        if(dp[i][first][second] != -1) return dp[i][first][second];
        
       
        int skip = solve(i + 1, nums, first, second,dp);

        
        int take1 = solve(i + 1, nums, __gcd(first, nums[i]), second,dp);

        
        int take2 = solve(i + 1, nums, first, __gcd(second, nums[i]),dp);
        
        
        return dp[i][first][second] = (0LL + skip + take1 + take2) % mod;
    }
    
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(201,vector<int>(201,-1)));
        return solve(0, nums, 0, 0,dp);
    }
};