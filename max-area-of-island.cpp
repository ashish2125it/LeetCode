class Solution {
public:
    int res = 0;
    void dfs(vector<vector<int>>& grid,vector<vector<int>> &vis,int i,int j,int n,int m,int ans)
    {
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]==0 || vis[i][j]==1) 
        {
           res = max(res,ans);
           return ;
        }

        vis[i][j]=1;


         dfs(grid,vis,i+1,j,n,m,ans+1);
         dfs(grid,vis,i-1,j,n,m,ans+1);
         dfs(grid,vis,i,j+1,n,m,ans+1);
         dfs(grid,vis,i,j-1,n,m,ans+1);

        return ;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));

        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && !vis[i][j])
                {
                    int ans = 1;
                   dfs(grid,vis,i,j,n,m,ans);
                  
            }
        }
        }

        return res;
    }
};