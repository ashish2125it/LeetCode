#define ll long long int
class Solution {
public:
    ll solve(ll i, ll j, vector<vector<int>>& nums, ll c, int n, int m, vector<vector<vector<ll>>>& dp) {
        
        if (i == n - 1 && j == m - 1) {
            if (c > 0) return max(0LL, (ll)nums[i][j]);
            return (ll)nums[i][j];
        }
        
       
        if (i >= n || j >= m) return LLONG_MIN;
        
        
        if (dp[i][j][c] != LLONG_MIN) return dp[i][j][c];

        
        if (nums[i][j] < 0) {
            ll d1 = LLONG_MIN, r1 = LLONG_MIN;
            ll d2 = LLONG_MIN, r2 = LLONG_MIN;
            
            
            if (c > 0) {
                d1 = solve(i + 1, j, nums, c - 1, n, m, dp);
                r1 = solve(i, j + 1, nums, c - 1, n, m, dp);
            }

           
            d2 = solve(i + 1, j, nums, c, n, m, dp);
            r2 = solve(i, j + 1, nums, c, n, m, dp);

           
            if (d2 != LLONG_MIN) d2 += (ll)nums[i][j];
            if (r2 != LLONG_MIN) r2 += (ll)nums[i][j];

           
            return dp[i][j][c] = max({d1, r1, d2, r2});
        }

       
        ll d2 = LLONG_MIN, r2 = LLONG_MIN;
        d2 = solve(i + 1, j, nums, c, n, m, dp);
        r2 = solve(i, j + 1, nums, c, n, m, dp);

       
        if (d2 != LLONG_MIN) d2 += (ll)nums[i][j];
        if (r2 != LLONG_MIN) r2 += (ll)nums[i][j];

       
        return dp[i][j][c] = max(d2, r2);
    }

    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size(), m = coins[0].size();
        vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(m, vector<ll>(3, LLONG_MIN)));
        ll result = solve(0, 0, coins, 2, n, m, dp);
        return result ;
    }
};
