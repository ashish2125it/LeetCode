class Solution {
public:
    void solve(int node, unordered_map<int, vector<int>>& mp, int& cnt, vector<int>& vis) {
        vis[node] = 1;

        for (auto it : mp[node]) {
            if (!vis[it]) {
                cnt++;  // Increment cnt directly
                solve(it, mp, cnt, vis);  // Pass cnt by reference
            }
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> mp;
        for (auto e : edges) {
            mp[e[0]].push_back(e[1]);
            mp[e[1]].push_back(e[0]);
        }

        vector<int> compo;
        vector<int> vis(n, 0);
        int sum = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                int cnt = 1;  // Initialize cnt for each component
                solve(i, mp, cnt, vis);
                sum += cnt;
                compo.push_back(cnt);
            }
        }

        long long ans = 0;
        for (int i = 0; i < compo.size(); i++) {
            long long ele = (long long)(sum - compo[i]);  // Explicit long long for ele
            ans += ele * compo[i];
        }

        return ans / 2;
    }
};
