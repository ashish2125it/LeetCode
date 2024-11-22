class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int, int>>> gr;
        for (auto it : roads) {
            gr[it[0]].push_back({it[1], it[2]});
            gr[it[1]].push_back({it[0], it[2]});
        }

        int mod = 1e9 + 7;

        
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;

        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0}); // {distance, node}

        while (!pq.empty()) {
            auto [curr_distance, node] = pq.top();
            pq.pop();

            
            if (curr_distance > dist[node]) {
                continue;
            }

            for (auto& [adj_Node, adj_dis] : gr[node]) {
                long long new_distance = curr_distance + adj_dis;

                if (new_distance < dist[adj_Node]) { // First time reaching adj_Node with shorter distance
                    dist[adj_Node] = new_distance;
                    ways[adj_Node] = ways[node];
                    pq.push({new_distance, adj_Node});
                } else if (new_distance == dist[adj_Node]) { // Found another shortest path
                    ways[adj_Node] = (ways[adj_Node] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1]%mod;
    }
};
