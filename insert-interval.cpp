class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& in, vector<int>& new_in) {
     vector<vector<int>> ans;
     sort(in.begin(),in.end());
     
     in.push_back(new_in);
     sort(in.begin(),in.end());
     int n = in.size();
     int start = in[0][0];
     int end=  in[0][1];
     for(int i=1;i<n;i++)
     {
          if(in[i][0]<=end)
          {
            end= max(end,in[i][1]);
          }
          else
          {
            ans.push_back({start,end});
            start = in[i][0];
            end = in[i][1];
          }
     }

     ans.push_back({start,end});
     return ans;

    }
};