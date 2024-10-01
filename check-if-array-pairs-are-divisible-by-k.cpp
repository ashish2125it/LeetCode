class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
    int n = arr.size();  
    unordered_map<int,int>mp;
    for(auto it:arr) mp[(it%k + k)%k]++;

    for(auto it:mp)
    {
        int rem = it.first;
        int next_rem = (k-rem)%k;
        if(mp[rem]!=mp[next_rem]) return 0;
        mp[rem] = 0;
        mp[next_rem] =0;

    }
    return 1;
    }
};