class Solution {
public:

int nrow[4] = {-1,0,1,0};
int ncol[4] = {0,1,0,-1};
int solve(int i,int j,vector<vector<int>>& grid,int n,int m, int h,vector<vector<int>>&vis,vector<vector<vector<int>>>&dp)
{
    if(i==n-1 && j==m-1)
    {
        if(h>0) return 1;
        return 0;
    }
    if(i>=n || i<0 || j<0 || j>=m || h<=0) return 0;
    if(dp[i][j][h]!=-1) return dp[i][j][h];

    vis[i][j] = 1;

   int ans= 0;
    for(int x=0;x<4;x++)
    {
        int row = i + nrow[x];
        int col = j + ncol[x];
        if(row<n && row>=0 && col<m && col>=0 && vis[row][col]==0)
        {
            if(grid[row][col]==1)
            ans = ans || solve(row,col,grid,n,m,h-1,vis,dp);
            else
            ans = ans || solve(row,col,grid,n,m,h,vis,dp);
        }
    }

    vis[i][j] = 0;
    return dp[i][j][h] = ans;

}
    bool findSafeWalk(vector<vector<int>>& grid, int h) {
    int n = grid.size(),m = grid[0].size();
    vector<vector<int>>vis(n,vector<int>(m,0));
    if(grid[0][0]==1) 
    h--;
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(h+1,-1)));
    int ans = solve(0,0,grid,n,m,h,vis,dp);
    if(ans) return 1;
    return 0;
    }
};