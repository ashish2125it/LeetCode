class Solution {
public:
    const int NEG_INF = -1000000000;
    int dp[2002][2002][2];
    int solve(const vector<int>& nums, const vector<int>& prefix, int index, int remaining, int canExtend, int m) {
        if(index == nums.size()) return remaining == 0 ? 0 : NEG_INF;
        if(dp[index][remaining][canExtend] != -1) return dp[index][remaining][canExtend];

        int best = NEG_INF;
        if(canExtend) {
            best = max(best, nums[index] + solve(nums, prefix, index + 1, remaining, 1, m));
            best = max(best, solve(nums, prefix, index, remaining, 0, m));
        } else {
            if(remaining == 0) return 0;
            best = max(best, solve(nums, prefix, index + 1, remaining, 0, m));
            if(nums.size() - index >= m) {
                int currentSum = prefix[index + m] - prefix[index];
                best = max(best, currentSum + solve(nums, prefix, index + m, remaining - 1, 1, m));
            }
        }

        return dp[index][remaining][canExtend] = best;
    }
    
    int maxSum(vector<int>& nums, int k, int m) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for(int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + nums[i];
        memset(dp, -1, sizeof(dp));
        return solve(nums, prefix, 0, k, 0, m);
    }
};