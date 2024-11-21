class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& e, vector<int>& d) {
     unordered_map<int,vector<pair<int,int>>>gr;
    for(auto &it:e) 
  {  gr[it[0]].push_back({it[1],it[2]});
     gr[it[1]].push_back({it[0],it[2]});
  }

    vector<int>ans(n,-1);  
   
    vector<int>vis(n,0);
    vis[0] = 0; 
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq; 
    pq.push({0,0}) ; //  {dist,node}  
    while(!pq.empty())
    {
        auto it = pq.top();
        int time = pq.top().first ;
        int node = pq.top().second;
        pq.pop();
         
        if(vis[node]==1 || d[node]<=time) continue;

        vis[node] = 1;

        ans[node] = time ;

        for(auto &[Node,length]:gr[node])
        {
             if(vis[Node]==0)
              pq.push({time+length,Node});
        }

    }

    return ans;
   







   


    }
};