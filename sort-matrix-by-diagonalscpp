class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        unordered_map<int, vector<int>> map1;
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                map1[i - j].push_back(grid[i][j]);
            }
        }

        for (auto &it : map1) {
            if (it.first < 0) {
                sort(it.second.begin(), it.second.end());
            } else {
                sort(it.second.begin(), it.second.end(), greater<int>());
            }
        }

        for (int i = n - 1; i >= 0; i--) {   
            for (int j = m - 1; j >= 0; j--) {
                int key = i - j;
                grid[i][j] = map1[key].back();
                map1[key].pop_back();
            }
        }

        return grid;
    }
};