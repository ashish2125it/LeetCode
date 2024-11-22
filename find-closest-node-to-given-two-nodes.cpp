class Solution {
public:
    vector<int> solve(int node, unordered_map<int, vector<int>>& gr, int n) {
        vector<int> dist(n, 1e9);
        dist[node] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, node}); // Correct initialization: {distance, node}

        while (!pq.empty()) {
            auto [distance, Node] = pq.top();
            pq.pop();

            // Ignore outdated distances
            if (distance > dist[Node]) continue;

            for (auto& it : gr[Node]) {
                if (dist[it] > distance + 1) {
                    dist[it] = distance + 1;
                    pq.push({dist[it], it});
                }
            }
        }
        return dist;
    }

    int closestMeetingNode(vector<int>& e, int node1, int node2) {
        unordered_map<int, vector<int>> gr;
        int n = e.size();

        // Build graph
        for (int i = 0; i < n; i++) {
            if (e[i] != -1) {
                gr[i].push_back(e[i]);
            }
        }

        // Compute distances from both nodes
        vector<int> d1 = solve(node1, gr, n);
        vector<int> d2 = solve(node2, gr, n);

        // Find the closest meeting node
        int dist = 1e9;
        int index = -1;
        for (int i = 0; i < n; i++) {
            if (d1[i] != 1e9 && d2[i] != 1e9) {
                int maxi = max(d1[i], d2[i]);
                if (dist > maxi) {
                    dist = maxi;
                    index = i;
                }
            }
        }

        return index; // Returns -1 if no valid node is found
    }
};
