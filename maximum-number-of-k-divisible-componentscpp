class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        if (n < 2) return 1;

        vector<vector<int>> gr(n);
        vector<int> inDegree(n);
        vector<long long> nodeValues(values.begin(), values.end());

        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            gr[u].push_back(v);
            gr[v].push_back(u);
            inDegree[u]++;
            inDegree[v]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 1) q.push(i);
        }

        int componentCount = 0;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            inDegree[cur]--;
            long long addValue = (nodeValues[cur] % k == 0) ? 0 : nodeValues[cur];
            if (addValue == 0) componentCount++;

            for (int neighbor : gr[cur]) {
                if (inDegree[neighbor] > 0) {
                    inDegree[neighbor]--;
                    nodeValues[neighbor] += addValue;
                    if (inDegree[neighbor] == 1) q.push(neighbor);
                }
            }
        }

        return componentCount;
    }
};