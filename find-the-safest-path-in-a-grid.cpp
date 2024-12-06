class Solution {
public:
    int nrow[4] = {-1, 0, 1, 0};
    int ncol[4] = {0, 1, 0, -1};
    
    // Depth-First Search for path validation
    bool solve(int i, int j, vector<vector<int>>& temp, int fact, int n, int m, vector<vector<int>>& vis) {
        if (i == n - 1 && j == m - 1) return true;

        vis[i][j] = 1;
        for (int x = 0; x < 4; x++) {
            int next_row = i + nrow[x];
            int next_col = j + ncol[x];
            if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < m 
                && vis[next_row][next_col] == 0 && temp[next_row][next_col] >= fact) {
                if (solve(next_row, next_col, temp, fact, n, m, vis)) 
                    return true;
            }
        }
        return false;
    }
    
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        // BFS to calculate the minimum Manhattan distances from thieves
        vector<vector<int>> temp(n, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    temp[i][j] = 0;
                }
            }
        }
        
        while (!q.empty()) {
            auto [row, col] = q.front(); q.pop();
            for (int d = 0; d < 4; d++) {
                int next_row = row + nrow[d];
                int next_col = col + ncol[d];
                if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < n 
                    && temp[next_row][next_col] > temp[row][col] + 1) {
                    temp[next_row][next_col] = temp[row][col] + 1;
                    q.push({next_row, next_col});
                }
            }
        }

        // Binary Search for maximum safeness factor
        int low = 0, high = n + n, final_ans = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            vector<vector<int>> vis(n, vector<int>(n, 0));
            if (temp[0][0] >= mid && solve(0, 0, temp, mid, n, n, vis)) {
                final_ans = mid; // Valid path found with this safeness factor
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return final_ans;
    }
};
