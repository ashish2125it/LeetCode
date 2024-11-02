class Solution {

public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& q) {
     int m = q.size();
    vector<int>ans(m,n);
    unordered_map<int,vector<int>>adj;
   
    for(int i=0;i<n-1;i++)
    adj[i].push_back(i+1);

    for(int i=0;i<m;i++)
    {
       int u = q[i][0];
       int v = q[i][1];
       adj[u].push_back(v);
       vector<int>dist(n,1e9);

       priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
       pq.push({0,0});
       dist[0] = 0;
       while(!pq.empty())
       {
        auto temp = pq.top();
        pq.pop();
        int node = temp.second;
        int distance = temp.first;
        
        if(dist[node]<distance) continue;
        for(auto it:adj[node])
        {
          if(dist[it]>1 + distance)
        {
            pq.push({distance+1,it});
            dist[it] = 1 + distance; 
        }
        }
       }
       
       ans[i] = dist[n-1];
    }

    return ans;


    }
};