class Solution {
public:
    int cnt = 0, sum = 0;
    unordered_map<int, vector<pair<int, int>>> gr;
    
    void dfs(int child, int par, int ss, int dist) {
        if (dist % ss == 0) cnt++;

        for (auto [c, d] : gr[child]) {
            if (c != par)
                dfs(c, child, ss, dist + d);
        }
    }

    vector<int> countPairsOfConnectableServers(vector<vector<int>>& e, int ss) {
        int n = e.size() + 1;
        vector<int> ans(n, 0);

       
        gr.clear();

        
        for (int i = 0; i < e.size(); i++) {
            gr[e[i][0]].push_back({e[i][1], e[i][2]});
            gr[e[i][1]].push_back({e[i][0], e[i][2]}); 
        }

        for (int par = 0; par < n; par++) {
            vector<int> temp;
            sum = 0;
            int t = 0;

            for (auto [ch, d] : gr[par]) {
                cnt = 0;
                dfs(ch, par, ss, d);
                temp.push_back(cnt);
                sum += cnt; 
            }

            for (auto it : temp)
                t += it * (sum - it);

            ans[par] = t / 2;
        }

        return ans;
    }
};
