class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& f, int src, int dst, int k) {
    unordered_map<int,vector<pair<int,int>>>gr;
    for(auto &it:f) 
    gr[it[0]].push_back({it[1],it[2]});  // {from -> vector< {to,cost} } 

    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq; // {dist,node,steps}

    pq.push({0,src,0});   // {dist,node,steps} 
    
    // main algo in Dijiskta in when we came later it will come with higher cost. If we reach at particuler node. It will come with lower cost. 
    
    // it always choose lower cost. 

    // if at any node prevous cost is lower and current cost is higher. So from this node greedy prevous path is better and current path cost is higher.
    // So don't choose current path. 
    // Ignore it. 

    

    vector<int>stops(n,INT_MAX);
    //stops[src] = 0;

    while(pq.size()>0)
    {
      //  auto it = pq.top();
        int dist = pq.top()[0];
        int node = pq.top()[1];
        int steps = pq.top()[2];

        pq.pop();
        if(steps > stops[node] || steps > k+1) continue; // whatever will come later will come higher cost. So ignore it.

        stops[node] = steps;
        if(node==dst) return dist;

        for(auto& [Node,distance]:gr[node])
        {
             pq.push({dist+distance,Node,steps+1});
        }

    }
    return -1;
    }
};