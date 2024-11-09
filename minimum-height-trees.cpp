class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& e) {
    vector<int>ans;
    if(n==1)
    {
        ans.push_back(0);
        return ans;
    }
   
     vector<vector<int>>gr(n);
     vector<int>d(n,0);

     for(int i=0;i<e.size();i++)
     {
        d[e[i][0]]++;
        d[e[i][1]]++;
        gr[e[i][0]].push_back(e[i][1]);
        gr[e[i][1]].push_back(e[i][0]);

     }

      queue<int>q;
      for(int i=0;i<n;i++)
      {
        if(d[i]==1) q.push(i);
      }

      while(n>2)
      {
         int size = q.size();
         n -= size;
         while(size>0)
         {
             int front = q.front();
             q.pop();
             for(auto it:gr[front])
             {
                 d[it]--;
                 if(d[it]==1)
                 q.push(it);
             }
            
             size--;
         }

      }

      while(q.size())
      {
        ans.push_back(q.front());
        q.pop();
      }
      return ans;

    }
};