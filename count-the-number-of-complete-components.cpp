class Solution {
public:
    void dfs(int src, vector<int>& vis, unordered_map<int, vector<int>>& gr, int& node, int& edges) {
        if (vis[src] == 1) return;
        
        vis[src] = 1; 
        node++;

        for (auto it : gr[src]) {
            edges++;  
            if (vis[it] == 0) {
                dfs(it, vis, gr, node, edges);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int cnt = 0;
        unordered_map<int, vector<int>> gr;

       
        for (auto it : edges) {
            gr[it[0]].push_back(it[1]);
            gr[it[1]].push_back(it[0]);
        }

        vector<int> vis(n, 0);

        
        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                int node = 0, edges = 0;
                dfs(i, vis, gr, node, edges);

                edges /= 2;  

                if ((node * (node - 1)) / 2 == edges) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
