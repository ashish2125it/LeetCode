class Solution {
public:
    int nrow[4] = {-1, 0, 1, 0};
    int ncol[4] = {0, 1, 0, -1};
    
    // DFS to check if a path exists with a given threshold
    bool solve(int i, int j, int fact, vector<vector<int>>& heights, int n, int m, vector<vector<int>>& vis) {
        if (i == n - 1 && j == m - 1) return true; // Reached the bottom-right cell

        vis[i][j] = 1;

        for (int k = 0; k < 4; k++) {
            int next_row = i + nrow[k];
            int next_col = j + ncol[k];
            
            if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < m 
                && !vis[next_row][next_col] 
                && abs(heights[i][j] - heights[next_row][next_col]) <= fact) {
                if (solve(next_row, next_col, fact, heights, n, m, vis)) {
                    return true;
                }
            }
        }

        return false;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        int low = 0, high = 0;

        // Determine the maximum possible effort
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < 4; k++) {
                    int next_row = i + nrow[k];
                    int next_col = j + ncol[k];
                    if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < m) {
                        high = max(high, abs(heights[i][j] - heights[next_row][next_col]));
                    }
                }
            }
        }

        int final_ans = 0;

        // Binary search over the effort
        while (low <= high) {
            int mid = (low + high) / 2;
            vector<vector<int>> vis(n, vector<int>(m, 0));
            if (solve(0, 0, mid, heights, n, m, vis)) {
                final_ans = mid;
                high = mid - 1; // Try to find a smaller effort
            } else {
                low = mid + 1; // Increase the effort
            }
        }

        return final_ans;
    }
};
