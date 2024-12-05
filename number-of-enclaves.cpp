class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
    int n = grid.size(),m = grid[0].size();
    queue<pair<int,int>>q;
    vector<vector<int>>vis(n,vector<int>(m,0));

    for(int i=0;i<n;i++)
    {
         if(grid[i][0]==1)
         {
            vis[i][0] = 1;
            q.push({i,0});
         }

         if(grid[i][m-1]==1)
         {
            vis[i][m-1] = 1;
            q.push({i,m-1});
         }
    }    



    for(int i=0;i<m;i++)
    {
        if(grid[0][i]==1)
        {
            q.push({0,i});
            vis[0][i] = 1;
        }

        if(grid[n-1][i]==1)
        {
            q.push({n-1,i});
            vis[n-1][i] =  1;
        }
    }

    int nrow[] = {-1,0,1,0};
    int ncol[] = {0,1,0,-1};
    while(!q.empty())
    {

        int row = q.front().first; 
        int col = q.front().second;
        q.pop();

        for(int i=0;i<4;i++)
        {
            int next_row = row + nrow[i];
            int next_col =  col + ncol[i];
            if(next_row>=0 && next_row<n && next_col>=0 && next_col<m && vis[next_row][next_col]==0 && grid[next_row][next_col]==1)
            {
                vis[next_row][next_col] = 1;
                q.push({next_row,next_col});
            }
        }
    }


    int ans= 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==1 && vis[i][j]==0)
            ans++;
        }
    }
    return ans;


    
    }
};