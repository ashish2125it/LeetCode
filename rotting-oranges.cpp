class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();

    queue<pair<int,pair<int,int>>>q;
    vector<vector<int>>vis(n,vector<int>(m,0));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==2)
            {
                q.push({0,{i,j}});
                vis[i][j] = 1;
            }
        }
    }

  //  if(q.size()==0) return -1;
   
    int nrow[] = {-1,0,1,0};
    int ncol[] = {0,1,0,-1};
    int tm =0 ;
    while(q.size())
    {
        int time = q.front().first;
        int row = q.front().second.first;
        int col = q.front().second.second;
        q.pop();
        tm = max(tm,time);

        for(int i=0;i<4;i++)
        {
               int next_row = row + nrow[i];
               int next_col = col + ncol[i];

               if(next_row>=0 && next_row<n && next_col>=0 && next_col<m && vis[next_row][next_col]==0 && grid[next_row][next_col]==1)
               {
                 q.push({time+1,{next_row,next_col}});
                 vis[next_row][next_col] = 1;
               }

        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==1 && vis[i][j]==0) return -1;
        }
    }

    return tm; 

      
    }
};