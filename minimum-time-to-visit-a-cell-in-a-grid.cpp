class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if (grid[0][1] > 1 && grid[1][0] > 1) return -1;

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0}); // {time, row, col}

        int nrow[] = {-1, 0, 1, 0};
        int ncol[] = {0, 1, 0, -1};
        vector<vector<int>> vis(n, vector<int>(m, 0));

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int time = it[0], row = it[1], col = it[2];

            if (vis[row][col]) continue; // Skip already visited cells
            vis[row][col] = 1;

            if (row == n - 1 && col == m - 1) return time;

            for (int i = 0; i < 4; i++) {
                int next_row = row + nrow[i];
                int next_col = col + ncol[i];

                if (next_row >= 0 && next_col >= 0 && next_row < n && next_col < m && !vis[next_row][next_col]) {
                    int next_time = time + 1;

                   
                    if (next_time < grid[next_row][next_col]) {
                        int wait = grid[next_row][next_col] - next_time;
                        if (wait % 2 != 0) wait++; 
                        next_time += wait;
                    }

                    pq.push({next_time, next_row, next_col});
                }
            }
        }

        return -1;
    }
};
