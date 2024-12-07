class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
    vector<vector<int>>ans;
    int n = in.size();
    sort(in.begin(),in.end());
    int start = in[0][0];
    int end = in[0][1];

   
    for(int i=1;i<n;i++)
    {
        if(in[i][0] <= end)
        {
           end = max(end,in[i][1]);
        }
        else
        {
            ans.push_back({start,end});
            start  = in[i][0];
            end = in[i][1];
        }
    }
    ans.push_back({start,end});
    return ans;
     
    // [{0,4} {1,4}] 
    }
};