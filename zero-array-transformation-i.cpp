class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& q) {
    int s = q.size();
    int n = nums.size();
    vector<int>temp(n,0);
    for(int i=0;i<s;i++)
    {
        temp[q[i][0]]++;
        if(q[i][1]+1<n) 
        temp[q[i][1]+1]--;
    }

    for(int i=1;i<n;i++)
    temp[i] += temp[i-1];

    for(int i=0;i<n;i++)
    {
        if(nums[i] > temp[i]) return 0;
    }

    return 1;
    }
};