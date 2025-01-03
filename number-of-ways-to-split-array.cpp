class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
    int n = nums.size();
     long long tot= 0;
    for(auto it:nums) tot += it;
    vector<long long>pre(n);
    pre[0] = nums[0];
    for(int i=1;i<n;i++) pre[i] = pre[i-1] + nums[i];
    
    int cnt= 0;
    for(int i=0;i<n-1;i++)
    {
        if(pre[i] >= tot-pre[i]) 
        cnt++;
    }

    return cnt;

    }
};