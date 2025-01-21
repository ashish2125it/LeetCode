#define ll long long int
class Solution {
public:
    ll solve(int i, int n, vector<int>& nums, vector<vector<int>>& cost, int m, int prev_col, int target, vector<vector<vector<ll>>>& dp) {
        if (target < 0) return LLONG_MAX; // Invalid target
        if (i == n) return target == 0 ? 0 : LLONG_MAX; // Base case

        if (dp[i][prev_col + 1][target] != -1) return dp[i][prev_col + 1][target]; // Memoization

        ll ans = LLONG_MAX;

        if (nums[i] != 0) { // House already painted
            int curr_col = nums[i] - 1; // Convert 1-based to 0-based
            if (curr_col == prev_col) {
                ans = solve(i + 1, n, nums, cost, m, curr_col, target, dp);
            } else {
                ans = solve(i + 1, n, nums, cost, m, curr_col, target - 1, dp);
            }
        } else { // House not painted
            for (int j = 0; j < m; j++) { // Try all colors
                ll temp;
                if (j == prev_col) {
                    temp = solve(i + 1, n, nums, cost, m, j, target, dp);
                } else {
                    temp = solve(i + 1, n, nums, cost, m, j, target - 1, dp);
                }
                if (temp != LLONG_MAX) {
                    ans = min(ans, cost[i][j] + temp);
                }
            }
        }

        return dp[i][prev_col + 1][target] = ans; 
    }

    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<ll>>> dp(m, vector<vector<ll>>(n + 2, vector<ll>(target + 1, -1))); 
        ll ans = solve(0, m, houses, cost, n, -1, target, dp);
        return ans == LLONG_MAX ? -1 : ans;
    }
};
