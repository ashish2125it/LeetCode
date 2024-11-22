class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> degrees(n);
        vector<vector<int>> g(n, vector<int>());

        for (auto& edge : edges) {
            g[edge[0]].push_back(edge[1]);
            degrees[edge[1]]++;
        }

        vector<vector<int>> anc(n, vector<int>());
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degrees[i] == 0)
                q.push(i);
        }

        vector<unordered_set<int>> dup(n);
        while (!q.empty()) {
            int fr = q.front();
            q.pop();
            for (int c : g[fr]) {
                dup[c].insert(fr);
                anc[c].push_back(fr);
                for (int gr : anc[fr]) {
                    if (dup[c].find(gr) == dup[c].end()) {
                        dup[c].insert(gr);
                        anc[c].push_back(gr);
                    }
                }
                degrees[c]--;
                if (degrees[c] == 0)
                    q.push(c);
            }
        }

        for (int i = 0; i < n; i++) {
            sort(anc[i].begin(), anc[i].end());
        }

        return anc;
    }
};