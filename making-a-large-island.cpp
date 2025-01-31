class Solution {
public:
    int nrow[4] = {0, -1, 0, 1};
    int ncol[4] = {-1, 0, 1, 0};

    void dfs(int i, int j, vector<vector<int>>& vis, vector<vector<int>>& grid, int n, int& cnt, int val) {
        for (int x = 0; x < 4; x++) {
            int next_row = i + nrow[x];
            int next_col = j + ncol[x];
            if (next_row < n && next_col < n && next_row >= 0 && next_col >= 0 && 
                grid[next_row][next_col] == 1 && vis[next_row][next_col] == 0) {
                vis[next_row][next_col] = 1;
                grid[next_row][next_col] = val;
                cnt++;
                dfs(next_row, next_col, vis, grid, n, cnt, val);
            }
        }
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        map<int, int> mp;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        int val = 2;  // Start island labeling from 2
        int max_island = 0;

        // Step 1: Label all islands with unique values and store their sizes
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && vis[i][j] == 0) {
                    vis[i][j] = 1;
                    grid[i][j] = val;
                    int cnt = 1;
                    dfs(i, j, vis, grid, n, cnt, val);
                    mp[val] = cnt;
                    max_island = max(max_island, cnt); // Track the max existing island
                    val++;
                }
            }
        }

        // Step 2: Try converting each `0` into `1` and calculate max possible island
        int ans = max_island;  // Start with the largest original island
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    set<int> st;
                    if (i + 1 < n) st.insert(grid[i + 1][j]);
                    if (i - 1 >= 0) st.insert(grid[i - 1][j]);
                    if (j + 1 < n) st.insert(grid[i][j + 1]);
                    if (j - 1 >= 0) st.insert(grid[i][j - 1]);

                    int temp = 1;
                    for (auto it : st) {
                        if (mp.find(it) != mp.end()) temp += mp[it];
                    }

                    ans = max(ans, temp);
                }
            }
        }

        return ans;
    }
};
