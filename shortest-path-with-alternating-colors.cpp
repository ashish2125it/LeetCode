class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red, vector<vector<int>>& blue) {
    vector<int>ans(n);
    unordered_map<int,vector<pair<int,int>>>gr;
    queue<pair<int,int>>q;
    q.push({0,0});  // {node,color}
    q.push({0,1});
    for(auto it:red)
    gr[it[0]].push_back({it[1],0});

     for(auto it:blue)
    gr[it[0]].push_back({it[1],1});

    // for red ->0 , for blue 1
    vector<vector<int>>dist(n,vector<int>(2,INT_MAX));  // dist[node][color]
    dist[0][0] = 0;
    dist[0][1] = 0;

    while(q.size()>0)
    {
        auto it = q.front();
        q.pop();
        int node = it.first;
        int color = it.second;

        for(auto it:gr[node])
        {
            int Node = it.first;
            int Curr_color = it.second;
            if(Curr_color!=color)
            {
                if(dist[Node][Curr_color]==INT_MAX)
                {
                    dist[Node][Curr_color] = 1 + dist[node][color] ;
                    q.push({Node,Curr_color});
                }
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        int mini = min(dist[i][0],dist[i][1]);
        if(mini==INT_MAX) 
        ans[i] = -1;
        else
        ans[i] = mini;
    }
    return ans;




    }
};