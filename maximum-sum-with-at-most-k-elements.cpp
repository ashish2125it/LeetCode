#define ll long long
class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
    priority_queue <vector<ll> > pq;
    unordered_map<int,int>mp;
    int n = grid.size();
    for(int i=0;i<n;i++)
   { sort(grid[i].begin(),grid[i].end());
      
      vector<ll>v(3);
      int j = grid[i].size()-1;
      v[0] = grid[i][j];
      v[1] = i;
      v[2] = j;
      pq.push(v);
      
   }
   
   ll ans= 0;
   while(k && pq.size()>0)
   {
       ll row = pq.top()[1];
       ll val = pq.top()[0];
       ll col = pq.top()[2];
       pq.pop();
       if(mp[row]<limits[row])
       {
          ans += val;
          k--;
          if(col-1>=0)
          pq.push({grid[row][col-1],row,col-1});
          mp[row]++;
       }
   }

   return ans;


    }
};