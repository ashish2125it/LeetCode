class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>>dist(n,vector<int>(m,0));
    vector<vector<int>>vis(n,vector<int>(m,0));

    queue<pair<int,pair<int,int>>>q;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(mat[i][j]==0)
            {
                q.push({0,{i,j}});
                vis[i][j] = 1;
                dist[i][j] = 0;
            }
        }
    }

   int nrow[] = {-1,0,1,0};
   int ncol[] = {0,1,0,-1};
   while(q.size()>0)
   {
       int steps = q.front().first;
       int row = q.front().second.first;
       int col = q.front().second.second;
       q.pop();

       dist[row][col] = steps;

       for(int i=0;i<4;i++)
       {
           int next_row = row + nrow[i];
           int next_col = col + ncol[i];

           if(next_row>=0 && next_row<n && next_col>=0 && next_col<m && vis[next_row][next_col]==0)
           {
            q.push({steps+1,{next_row,next_col}});
            vis[next_row][next_col] = 1;
           }
       }
      
   }

   return dist;


    }
};