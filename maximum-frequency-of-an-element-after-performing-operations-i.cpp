class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int op) {
    int n = nums.size();
    map<int,int>mp;
    vector<pair<int,int>>ev;
    for(auto it:nums) 
    { mp[it]++;
      ev.push_back({it-k,1});
      ev.push_back({it,2});
      ev.push_back({it+k,3});
    }
    sort(ev.begin(),ev.end());
    int cnt= 0;
    int res =0;
    for(auto& [num,type]:ev)
    {
        if(type==1) cnt++;
        else if(type==3) cnt--;
        

        int req_op = cnt - mp[num];
        res =  max(res,mp[num] + min(req_op,op)) ;
    }

   return res;

    }
};