class Solution {
public:
    int largestCombination(vector<int>& c) {
    int n = c.size();
    int ans = 0;
    for(int i=0;i<32;i++)
    {
        int cnt= 0;
        for(int j=0;j<n;j++)
        {
           if(c[j] & (1<<i)) cnt++;
        }
        ans =max(ans,cnt);
    }
    return ans;



    }
};