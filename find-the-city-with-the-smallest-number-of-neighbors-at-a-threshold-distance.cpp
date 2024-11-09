class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int d) {
        vector<vector<int>> min_cost(n, vector<int>(n, 1e9)); 

       
        for (int i = 0; i < n; i++) {
            min_cost[i][i] = 0;
        }

       
        for (auto& it : edges) {
            int start = it[0];
            int end = it[1];
            int cost = it[2];
            min_cost[start][end] = cost;
            min_cost[end][start] = cost;
        }

        
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (min_cost[i][j] > min_cost[i][k] + min_cost[k][j]) {
                        min_cost[i][j] = min_cost[i][k] + min_cost[k][j];
                    }
                }
            }
        }

      
        int ans = INT_MAX, city = -1;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && min_cost[i][j] <= d) {
                    cnt++; 
                }
            }

           
            if (cnt <= ans) {
                ans = cnt;
                city = i;
            }
        }
        
        return city; 
    }
};
