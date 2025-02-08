class Solution {
public:
    double dfs(int node, unordered_map<int, vector<int>>& gr, int time, int start_time, int target_node, vector<int>& vis) {
        if (start_time == time) {
            return node == target_node ? 1.0 : 0.0;
        }

        int count = 0;
        for (int next_node : gr[node]) {
            if (!vis[next_node]) count++;
        }

        if (node == target_node) {
            return count == 0 ? 1.0 : 0.0;
        }

        double prob = 0.0;
        for (int next_node : gr[node]) {
            if (!vis[next_node]) {
                vis[next_node] = 1;
                prob += dfs(next_node, gr, time, start_time + 1, target_node, vis) * (1.0 / count);
                vis[next_node] = 0;  // Backtrack
            }
        }
        return prob;
    }

    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        unordered_map<int, vector<int>> gr;
        for (auto& it : edges) {
            int src = it[0], dest = it[1];
            gr[src].push_back(dest);
            gr[dest].push_back(src);
        }

        vector<int> vis(n + 1, 0);
        vis[1] = 1;
        
        return dfs(1, gr, t, 0, target, vis);
    }
};
