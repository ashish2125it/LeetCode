class Solution {
public:
void solve(int src,int dest,vector<int>&temp,vector<vector<int>>&ans, unordered_map<int,vector<int>>gr,vector<int>&vis)
{
    if(src==dest)
    {
        temp.push_back(dest);
        ans.push_back(temp);
        temp.pop_back();
        return ;
    }
    
    if(vis[src]==1)
    return ;

    vis[src] =  1;
    temp.push_back(src);

    

    for(auto it:gr[src])
    {
        if(vis[it]==0)
        {
            solve(it,dest,temp,ans,gr,vis);
        }
    }

     vis[src] =  0;
    temp.pop_back();
    
}
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
     vector<vector<int>>ans;
     unordered_map<int,vector<int>>gr;
     int n = graph.size();
     vector<int>vis(n,0);
    // vis[0]= 1;
     for(int i=0;i<n;i++)
     {
        for(auto it:graph[i])
         gr[i].push_back(it);
     }
     
     vector<int>temp; 
     solve(0,n-1,temp,ans,gr,vis);
     return ans;

    }
};