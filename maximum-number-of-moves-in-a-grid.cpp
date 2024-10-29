class Solution {
    int solve(int i, int j, vector<vector<int>>& grid, int n, int m, vector<vector<int>>& dp) {
        if (j == m - 1) return 0; 

        if (dp[i][j] != -1) return dp[i][j];

        int way1 = 0, way2 = 0, way3 = 0;

        
        if (i - 1 >= 0 && j + 1 < m && grid[i - 1][j + 1] > grid[i][j]) {
            way1 = 1 + solve(i - 1, j + 1, grid, n, m, dp);
        }

       
        if (j + 1 < m && grid[i][j + 1] > grid[i][j]) {
            way2 = 1 + solve(i, j + 1, grid, n, m, dp);
        }

        
        if (i + 1 < n && j + 1 < m && grid[i + 1][j + 1] > grid[i][j]) {
            way3 = 1 + solve(i + 1, j + 1, grid, n, m, dp);
        }

        return dp[i][j] = max({way1, way2, way3});
    }

public:
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;

        
        vector<vector<int>> dp(n, vector<int>(m, -1));

        for (int i = 0; i < n; i++) {
            ans = max(ans, solve(i, 0, grid, n, m, dp)); 
        }

        return ans;
    }
};
