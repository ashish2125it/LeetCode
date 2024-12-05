class Solution {
int ans= 0;
void solve(int city,unordered_map<int,vector<int>>mp,vector<int>&vis)
{

    vis[city] = 1;

    for(auto it:mp[city])
    {
        if(!vis[it])
        solve(it,mp,vis);
    }


}
public:
    int findCircleNum(vector<vector<int>>& c) {
    unordered_map<int,vector<int>>mp;
    int n = c.size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(c[i][j]==1)
            {
                mp[i].push_back(j);
            }
        }
    }

    vector<int>vis(n,0);
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            solve(i,mp,vis);
            ans++;
        }
    }

    return ans;
    }
};