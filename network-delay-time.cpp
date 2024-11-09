class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    
    vector<vector<int>>min_cost(n+1,vector<int>(n+1,1e9));

    for(int i=0;i<=n;i++) min_cost[i][i] = 0 ;

    for(auto it:times)
    {
        min_cost[it[0]][it[1]] = it[2];
    }

    for (int k = 1; k <= n; k++) {  
    for (int i = 1; i <= n; i++) {  
        for (int j = 1; j <= n; j++) { 
           
            min_cost[i][j] = min(min_cost[i][j], min_cost[i][k] + min_cost[k][j]);
        }
    }
}



 int dist = -1;
 for(int i=1;i<=n;i++)
 {
    if(min_cost[k][i]>=1e9) return -1;

    dist = max(dist,min_cost[k][i]);
 }
 return dist;
    }
};