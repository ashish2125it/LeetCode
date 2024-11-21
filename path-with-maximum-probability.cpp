class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& e, vector<double>& p, int start_node, int end) {
        unordered_map<int, vector<pair<int, double>>> gr;

        for (int i = 0; i < e.size(); i++) {
            gr[e[i][0]].push_back({e[i][1], p[i]});
            gr[e[i][1]].push_back({e[i][0], p[i]});
        }

       
        priority_queue<pair<double, int>> pq;
        vector<double> maxProb(n, 0.0);
        maxProb[start_node] = 1.0;
        pq.push({1.0, start_node});

        while (!pq.empty()) {
            auto [prob, node] = pq.top();
            pq.pop();

           
            if (node == end) return prob;

           
            for (auto &[next, edgeProb] : gr[node]) {
                double newProb = prob * edgeProb;
                if (newProb > maxProb[next]) {
                    maxProb[next] = newProb;
                    pq.push({newProb, next});
                }
            }
        }

        return 0.0;
    }
};
